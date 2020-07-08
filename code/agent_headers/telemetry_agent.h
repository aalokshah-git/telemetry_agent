/************************************************************************
 * Copyright (c) 2018, Volansys Technologies.
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
 *
 * Author : Aalok Shah
 * Date : March-2018
 ************************************************************************/
/**
 * \file telemetry_agent.h
 * \brief
 */


#ifndef TELEMETRYAGENT_H
#define TELEMETRYAGENT_H

/*******************
 * Includes
 *******************/
#include "agent_types.h"

/************************
 * Function prototypes
 ************************/
/**
* @brief This function is use for start telemetry Agent
*
* @param devCount		- [in] number of devices
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS startTelemetryAgent(uint32_t devCount);

/**
* @brief This function is use for stop telemetry Agent
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS stopTelemetryAgent(void);

#endif //TELEMETRYAGENT_H
