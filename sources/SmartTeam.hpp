#pragma once
#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {
        public:
            Character& passOverTheTeam() override;
    };
}