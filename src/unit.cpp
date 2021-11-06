#include "unit.hpp"

std::string unitNameToString(UnitNameLabel label)
{
    switch (label)
    {
        case UnitNameLabel::second:
            return "second";
        case UnitNameLabel::meter:
            return "meter";
        case UnitNameLabel::gram:
            return "gram";
        case UnitNameLabel::hertz:
            return "hertz";
    }
    return "";
}
