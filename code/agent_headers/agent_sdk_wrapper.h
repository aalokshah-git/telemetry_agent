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
 * \file agent_sdk_wrapper.h
 * \brief
 */

#ifndef AGENTSDKWRAPPER_H
#define AGENTSDKWRAPPER_H

/*******************
 * Includes
 *******************/
#include "agent_types.h"

/*********************
* Structures and Enum
***********************/
typedef enum telAgentPortAttr
{
    PORT_IS_INITIALIZED,        ///< 0 - Chech weather port is initialized
    NUM_OF_QUEUES_PER_PORT,     ///< 1 - Get number of queue per port
    MAX_NUM_OF_PORT_ATTRS       ///< 2 - Maximum supported commands for port
} telAgentPortAttr;

typedef enum telAgentQueueAttr
{
    QUEUE_DROP_COUNTER,         ///< 0 - Get current drop count of queue
    QUEUE_CAPACITY,             ///< 1 - Get capacity of queue
    QUEUE_CURRENT_OCCUPANCY,    ///< 2 - Get current occupancy of queue
    MAX_NUM_OF_QUEUE_ATTRS      ///< 3 - Maximum supported commands for queue
} telAgentQueueAttr;

typedef enum telAgentDeviceAttr
{
    NUM_OF_PORTS,               ///< 0 - Get number of ports
    DEVICE_TYPE,                ///< 1 - Get device type
    NUM_OF_TABLES,              ///< 2 - Get number of tables
    MAX_NUM_OF_DEVICE_ATTRS     ///< 3 - Maximum supported commands for device
} telAgentDeviceAttr;

typedef enum telAgentAutoQueueReconfigureAttr
{
    AUTO_RECONFIGURE_ENABLE,        ///< 0 - Disable auto reconfigure feature
    AUTO_RECONFIGURE_DISABLE,       ///< 1 - Enable auto reconfigure feature
    MAX_NUM_OF_AUTO_RECONFIGURE_ATTRS   ///< 2 - Maximum supported commands for auto reconfigure
} telAgentAutoQueueReconfigureAttr;

typedef struct telAgentWrapperFunctions
{
    /**
     * @brief get current cpu temperature in celsius
     *
     * @param devId         - [in] device id
     * @param temperature   - [out] temperature
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetTemperature)(uint32_t devId, float* temperature);
    /**
     * @brief get port specific info
     *
     * @param devId      - [in] device id
     * @param portId     - [in] port number
     * @param portAttr   - [in] attribute to get
     * @param portInfo   - [out] expected attribute
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetPortInfo)(uint32_t devId, uint8_t portId, telAgentPortAttr portAttr,
            uint32_t* portInfo);
    /**
     * @brief get statistics of port given by portId
     *
     * @param devId      - [in] device id
     * @param portId     - [in] port number
     * @param statistics - [out] structure pointer to store port statistics
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetPortStats)(uint32_t devId, uint8_t portId,
            telAgentPortStatistics* statistics);
    /**
     * @brief get queue info of port given by portNum
     *
     * @param devId      - [in] device id
     * @param portId     - [in] port number
     * @param queueNum   - [in] queue number
     * @param queueAttr  - [in] queue attribute
     * @param queueInfo  - [out] queue info
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetQueueInfo)(uint32_t devId, uint8_t portId, uint8_t queueNum,
            telAgentQueueAttr queueAttr, uint64_t* queueInfo);
    /**
     * @brief get table configuration data of device
     *
     * @param devId              - [in] device id
     * @param tableTotal         - [out] number of tables
     * @param tableConfigData    - [out] strcture pointer to store table configuration
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetAllTableInfo)(uint32_t devId, uint8_t* tableTotal,
            telAgentTableConfig* tableConfigData);
    /**
     * @brief get table metrics data of device
     *
     * @param devId              - [in] device id
     * @param tableTotal         - [out] number of tables
     * @param flowDataMatrics    - [out] strcture pointer to store table matrics data
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetFlowData)(uint32_t devId, uint8_t* tableTotal,
            telAgentTableFlowMetrics* flowDataMatrics);
    /**
     * @brief get buffer statistics of port given by portId
     *
     * @param devId          - [in] device id
     * @param portId         - [in] port number
     * @param curBufStat     - [out] current utilization of buffer
     * @param totalBufStat   - [out] total available buffer
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetBufInfoForPort)(uint32_t devId, uint8_t portId, uint32_t* curBufStat,
            uint32_t* totalBufStat);
    /**
     * @brief get buffer statistics of device
     *
     * @param devId          - [in] device id
     * @param curBufStat     - [out] current utilization of buffer
     * @param totalBufStat   - [out] total available buffer
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetBufInfoForDevice)(uint32_t devId, uint32_t* curBufStat,
            uint32_t* totalBufStat);
    /**
     * @brief get device info
     *
     * @param devId      - [in] device id
     * @param devAttr    - [in] attribute to get
     * @param devInfo    - [out] expected attribute
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperGetDeviceInfo)(uint32_t devId, telAgentDeviceAttr devAttr, uint8_t* devInfo);
    /**
     * @brief check whether device is initialised or not
     *
     * @param devId      - [in] device id
     *
     * @return AGENT_NO_ERR - device is initialised
     */
    AGENT_STATUS(*telAgentWrapperDeviceInited)(uint32_t devId);
    /**
     * @brief enable or disable packet trapping to CPU for perticular port by setting IACL rules
     *
     * @param devId      - [in] device id
     * @param portId     - [in] port number
     * @param trapAttr   - [in] command to execute any one from telAgentPacketTrap
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperPacketTrapPerPort)(uint32_t devId, uint8_t portId, telAgentPacketTrap trapAttr);
    /**
     * @brief reset queue drop counter by port id
     *
     * @param devId          - [in] device id
     * @param portId         - [in] port number
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperResetDropCounter)(uint32_t devId, uint8_t portId);
    /**
     * @brief This function is use for changing queue of specific port when congession detected
     *
     * @param devId                  - [in] device Id
     * @param srcportId              - [in] source port number
     * @param dstportId              - [in] Destination port number
     * @param queueId                - [in] Queue Id
     * @param autoReconfigureAttr    - [in] Auto reconfigure attr
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentWrapperChangeQueueForAgressor)(uint32_t devId, uint8_t srcportId, uint8_t dstportId,
            uint32_t queueId, telAgentAutoQueueReconfigureAttr autoReconfigureAttr);
    /**
     * @brief change mode for queue WM as given by mode
     *
     * @param devId      - [in] device Id
     * @param portId     - [in] port Id
     * @param mode       - [in] mode
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentPacketTrakkerChnageState)(uint32_t devId, uint8_t portId, uint8_t mode);
} telAgentWrapperFunctions;

/**
* @brief Perform parsing on Packets
*
* @param  devId     - [in] Device Id
* @param  pktInfo   - [in] Packet Info
* @param  buf       - [in] Packet
* @param  bufSize   - [in] Packet Size
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentWrapperControlPacketCallback(uint32_t devId, telAgentPktInfo *pktInfo,
        void *buf, uint16_t bufSize);

/**
* @brief This API is expected to register function pointer to agentWrapperApis,
*       and also register callback function for packet trapping
*
* @param agentWrapperApis   - [out] Function pinter structure to be filled
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentSdkAdapterInit(telAgentWrapperFunctions *agentWrapperApis);

#endif //AGENTSDKWRAPPER_H
