//-- Copyright 2016 Intrig
//-- See https://github.com/intrig/xenon for license.
#include <iostream>
#include <vector>
#include <xenon/xenon.h>
#include <xenon/xddl_code.h>
#include <ict/command.h>

using std::cout;
using std::cerr;

int main(int argc, char** argv) {
    try {
        int iterations = 3000;
        bool pretty = false;
        ict::command line("xmlperf", "Decode xenon::message to xml", "xmlperf xddl-dir");
        line.add(ict::option("pretty", 'p', "Convert to pretty xml", [&]{ pretty = true; }));
        line.add(ict::option("iterations", 'i', "Number of iterations", std::to_string(iterations), 
            [&](const std::string & i) {
                iterations = std::stoi(i);
            }));

        line.parse(argc, argv);
        if (line.targets.size() != 1) IT_FATAL("Exactly one argument is required, the path to the xddl directory.");

        ict::timer time;

        auto icd = line.targets[0] + "/icd.xddl";

        xenon::spec_server doc(icd);
        auto msg = xenon::parse(doc, "0101046B102C000114E03003603800203801C03801E03801F030037030002030"
              "00903000603000E0300120300130380000300110300030380080300200300210"
              "3001903001603000F03000703000403000C03000503000D1A03C9E16C18070DE"
              "2C7CFF3C7CC1001E00E01C000389");

        if (pretty) {
            time.start();
            for (auto i=0; i < iterations; ++i) {
                xenon::xml_type xml(xenon::to_xml(msg));
                auto x = xml.str();
            }
            time.stop();
        } else {
            time.start();
            for (auto i=0; i < iterations; ++i) {
                auto s = xenon::to_xml(msg);
            }
            time.stop();
        }
        cerr << time << '\n';

        

    } catch (std::exception & e) { 
        cerr << e.what() << '\n';
        return 1;
    }
}
