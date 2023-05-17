#pragma once
#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {
        public:
            Character& passOverTheTeam() override;

    };
}