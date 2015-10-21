#pragma once
//-- Copyright 2015 Intrig
//-- see https://github.com/intrig/xenon for license
#include <ict/message.h>
#include <ict/spec.h>

namespace ict {
// TODO make this work with const reference
inline bitstring serialize(message & m) {
    obitstream bs;
    recurse(m.root(), [&](const message::cursor & self, const message::cursor &) {
        if (self->consumes()) bs << self->bits;
    });
    return bs.bits();
}

message parse(spec & spec, ibitstream & bs);

message parse(spec & spec, const bitstring & bits);

}
