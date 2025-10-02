/*
 * This file is part of the ev mustang dashboard project.
 *
 * Copyright (C) 2025 Christian Kelly <chrskly@chrskly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdint.h>

#include "settings.h"

enum State {
    STANDBY,
    DRIVE,
    BATTERY_HEATING,
    CHARGING,
    BATTERY_EMPTY,
    OVERTEMP_FAULT,
    ILLEGAL_STATE_TRANSITION,
    CRITICAL_FAULT
};

enum InhibitReason {
    R_NONE,
    R_TOO_HOT,
    R_TOO_COLD,
    R_BATTERY_FULL,
    R_BATTERY_EMPTY,
    R_CHARGING,
    R_ILLEGAL_STATE_TRANSITION,
    R_MODULE_UNRESPONSIVE,
    R_SHUNT_UNRESPONSIVE,
    R_CRITICAL_FAULT,
    R_DEAD_CELL,
};

class BMS {
    public:
        BMS();
        void setState(State newState);

    private:
        State currentState;
        uint8_t soc;

        //
        bool internalError;
        bool packsImbalanced;
        bool shuntIsDead;
        bool illegalStateTransition;
        bool modulesDead;
        bool inhibitCharge;
        bool inhibitDrive;
        bool heaterEnabled;
        bool ignitionOn;
        bool chargeEnabled;

        InhibitReason chargeInhibitReason;
        InhibitReason driveInhibitReason;
        bool posContactorWelded;
        bool negContactorWelded;
        bool packContactorsWelded[NUM_PACKS];
 };