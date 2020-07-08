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
 * \file agent_cloud_wrapper.h
 * \brief
 */

#ifndef AGENTCLOUDWRAPPER_H
#define AGENTCLOUDWRAPPER_H

/*******************
 * Includes
 *******************/
#include "agent_types.h"

/*********************
* Structures and Enum
***********************/
typedef enum telAgentSendMsgFormats
{
    REGISTER_DEVICE,                    ///< 0 - device registration
    HEARTBEAT_ALIVE,                    ///< 1 - heartbeat
    TEMPERATURE,                        ///< 2 - temperature
    CPU_LOAD,                           ///< 3 - CPU load
    PORT_STATISTICS,                    ///< 4 - port statistics
    BUFFER_DEVICE_STATISTICS,           ///< 5 - buffer statistics of device
    BUFFER_PORT_STATISTICS,             ///< 6 - buffer statistics of port
    QUEUE_STATISTICS,                   ///< 7 - queue statistics
    TABLE_CONFIG,                       ///< 8 - table configuration
    FLOWDATA_METRICS,                   ///< 9 - Table Current Metrics
    INBAND_TELEMETRY_PACKET_INFO,       ///< 10 - Inband telemetry packet
    CAVIUM_PT_PACKET_QUEUE_INFO,        ///< 11 - PT queue packet
    CAVIUM_PT_PACKET_PORT_INFO,         ///< 12 - PT port packet
    PACKET_DISSECTOR_PACKET_INFO,       ///< 13 - packet dissector message
    EXCEPTION_MONITORING_PACKET_INFO,   ///< 14 - exception monitoring message
    MSG_RCV_ADDR,                       ///< 15 - receive message from cloud
    SOURCE_PORT_DISTRIBUTION,           ///< 16 - source port distribution(congestion analysis)
    MAX_SEND_MSG_FORMAT_SUPPORTED       ///< 17 - maximum support message formation
} telAgentSendMsgFormats;

typedef enum telAgentRecvCommands
{
    OPTIONAL_POLLING_INTERVAL,  ///< 0 - to change polling interval of poll based features
    COMPULSORY_POLLING_INTERVAL,///< 1 - to change compulsory polling interval of poll based features
    MAX_RECV_COMMAND_SUPPORTED  ///< 2 - max supported command
} telAgentRecvCommands;

typedef enum telAgentRecvCommandsForQueue
{
    QUEUE_DROP_COUNTER_RESET,               ///< 0 - Reset drop count value of all queues of port
    MAX_RECV_COMMAND_SUPPORTED_FOR_QUEUE    ///< 1 - max supported command
} telAgentRecvCommandsForQueue;

typedef enum telAgentRecvCommandsForPort
{
    START_PACKET_DISSECTOR,             ///< 0 - Start packet dissector
    STOP_PACKET_DISSECTOR,              ///< 1 - Stop packet dissector
    MAX_RECV_COMMAND_SUPPORTED_FOR_PORT ///< 2 - max supported command
} telAgentRecvCommandsForPort;

typedef enum telAgentFeatureCmd
{
    FEATURE_DISABLE,    ///< 0 - disable feature
    FEATURE_ENABLE      ///< 1 - enable feature
} telAgentFeatureCmd;

typedef enum telAgentRecvCommandForExceptionMonitoring
{
    UPDATE_REASONCODE_LIST,                     ///< 0 - Update list of reason code
    RESET_REASONCODE_LIST,                      ///< 1 - Reset list of reason code
    MAX_RECV_COMMAND_SUPPORTED_FOR_EXCEPTION    ///< 2 - max supported command
} telAgentRecvCommandForExceptionMonitoring;

typedef enum telAgentFeatureList
{
    CPU_TEMPERATURE,            ///< 0 - CPU temperature
    CPU_UTILIZATION,            ///< 1 - CPU utilization
    CPU_HEALTH_STAT,            ///< 2 - health stat(heartbeat)
    PORT_STAT,                  ///< 3 - port statistics
    QUEUE_STAT,                 ///< 4 - queue statistics
    TABLE_FLOW,                 ///< 5 - table metrics
    BUFFER_PER_PORT,            ///< 6 - buffer statistics per port
    BUFFER_FOR_DEVICE,          ///< 7 - buffer statistics of device
    INBAND_TELEMETRY,           ///< 8 - inband telemetry packets
    CAVIUM_PACKET_TRACKER,      ///< 9 - PT queue statistics
    PKT_DISSECTOR,              ///< 10 - packet dissector
    AGRESSOR_VS_VICTIM_DIST,    ///< 11 - source port distribution
    AUTO_QUEUE_CHANGE,          ///< 12 - queue changeover
    EXCEPTION_MONITORING,       ///< 13 - exception monitoring
    TABLE_FLOW_CONFIG,          ///< 14 - table configuration
    MAX_FEATURE_LIST            ///< 15 - max supported feature
} telAgentFeatureList;

typedef struct telAgentFeatureConfig
{
    uint32_t optionalPollingInterval;   ///< optional polling interval
    uint32_t compulsoryPollingInterval;   ///< compulsory polling interval
    uint8_t  threshold;         ///< threshold value
} telAgentFeatureConfig;

typedef struct telAgentCommWrapperFunctions
{
    /**
     * @brief Check weather Communication channel with server is up or not.
     *
     * @return AGENT_NO_ERR - Channel is up
     */
    AGENT_STATUS(*telAgentIsCommChannelInited)();

    /**
     * @brief send message to the server with appropriate
     *      format given by msgType.
     *
     * @param devId      - [in] device id
     * @param msgType    - [in] message type
     * @param msg        - [in] message to send
     * @param MsgLength  - [in] length of message
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentSendMessage)(uint32_t devId, telAgentSendMsgFormats msgType,
                                       void* msg, uint32_t MsgLength);

    /**
     * @brief send message to the server for specified port
     *      with appropriate format given by msgType.
     *
     * @param devId      - [in] device id
     * @param portId     - [in] dort id
     * @param msgType    - [in] message type
     * @param msg        - [in] message to send
     * @param MsgLength  - [in] mength of message
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentSendMessageForPort)(uint32_t devId, uint16_t portId,
            telAgentSendMsgFormats msgType, void* msg, uint32_t MsgLength);

    /**
     * @brief Receive message from the server.
     *
     * @param devId     - [in] Device Id
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentReceiveMessage)(uint32_t devId);

    /**
     * @brief This API is supposed to format INT message and send it to the server.
     *
     * @param switchTotal    - [in] total number of switch in header
     * @param metaFlags      - [in] INT meta data
     * @param switchInfo     - [in] switchs info
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentFormatAndSendMsgForIntCollector)(uint8_t switchTotal,
            telAgentIntOptMetaFlags metaFlags, telAgentIntSwitchInfo *switchInfo, char *msgPayload,
            uint16_t *msgLength);
} telAgentCommWrapperFunctions;

/* To handle receive commands from cloud */

/**
* @brief To handle request from the server (like feature enable/disable)
*
* @param    devId            -  [in] device Id
* @param    rcvCmd           -  [in] Received commands from server
* @param    cmdVal           -  [in] Command type
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentReceiveCommand(uint32_t devId, telAgentRecvCommands rcvCmd, uint32_t cmdVal);

/**
* @brief  To handle queue specific request from the server (like reset drop counter)
*
* @param    devId            -  [in] device Id
* @param    rcvCmd           -  [in] Received commands from server
* @param    portId           -  [in] Port Id
* @param    queueId          -  [in] QueueId
* @param   thresoldVal      -  [in] Threshold value
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentReceiveCommandForQueue(uint32_t devId, telAgentRecvCommandsForQueue rcvCmd,
        uint8_t portId, uint8_t queueId, uint8_t thresoldVal);

/**
* @brief  To handle port specific request from the server (like star/stop PD)
*
* @param    devId            -  [in] device Id
* @param    rcvCmd           -  [in] Received commands from server
* @param    portId           -  [in] Port Id
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentReceiveCommandForPort(uint32_t devId, telAgentRecvCommandsForPort rcvCmd,
        uint8_t portId);

/**
* @brief  To handle Feature request from the server
*
* @param devId                  - [in] Device Id
* @param featureCnfig           - [in] Feature configuration
* @param featureType            - [in] Type of feature
* @param stat                   - [in] Feature stat
* @return AGENT_NO_ERR - success
*
*/
AGENT_STATUS telAgentReceiveCommandForUpdateFeatureList(uint32_t devId,
        telAgentFeatureConfig featureCnfig, telAgentFeatureList featureType, telAgentFeatureCmd stat);

/**
* @brief To handle Network exception request
*
* @param    devId            -  [in] device Id
* @param    rcvCmd           -  [in] Received commands from server
* @param    reasoncodeList   -  [in] List of reason codes
* @param    totalReasonCode  -  [in] Number of reason codes
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentReceiveCommandForExceptionMonitoring(uint32_t devId,
        telAgentRecvCommandForExceptionMonitoring rcvCmd, telAgentReasonCode *reasoncodeList,
        uint8_t totalReasonCode);

typedef struct telAgentMsgFormatWrapperFunctions
{
    /**
     * @brief Fill msgPayload with data specified in statistics
     *   this API will Fill message with statistics of port
     *
     * @param devId          - [in] device id
     * @param portId         - [in] port id
     * @param statistics     - [in] Structure variable Filled with port statistics
     * @param msgPayload     - [out] Message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatPortStatistics)(uint32_t devId, uint16_t portId,
            telAgentPortStatistics statistics, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in statistics
     *   this API will Fill message with statistics of queue
     *
     * @param devId          - [in] device id
     * @param portId         - [in] port id
     * @param queueTotal     - [in] total queue
     * @param statistics     - [in] structure variable Filled with queue statistics
     * @param msgPayload     - [out] Message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatQueueStatistics)(uint32_t devId, uint16_t portId,
            uint8_t queueTotal, telAgentQueueStatistics* statistics,
            char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in statistics
     *   this API will Fill message with statistics of device total buffer
     *
     * @param devId          - [in] device id
     * @param statistics     - [in] structure variable Filled with buffer statistics
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatBufferDeviceStatistics)(uint32_t devId,
            telAgentBufferStatstics statistics, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in statistics
     *   this API will Fill message with statistics of per port buffer
     *
     * @param devId          - [in] device id
     * @param portId         - [in] port id
     * @param statistics     - [in] structure variable Filled with buffer statistics
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatBufferPortStatistics)(uint32_t devId, uint16_t portId,
            telAgentBufferStatstics statistics, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with defined message format for INT packet
     *
     * @param devId          - [in] device id
     * @param switchTotal    - [in] total number of switch in header
     * @param metaFlags      - [in] INT meta data
     * @param switchInfo     - [in] switchs info
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatInbandTelemetryPktData)(uint32_t devId, uint8_t switchTotal,
            telAgentIntOptMetaFlags metaFlags, telAgentIntSwitchInfo* switchInfo,
            char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in ptQueueData
     *   this API will Fill message with data of PT for queue
     *
     * @param devId          - [in] device id
     * @param ptQueueData    - [in] structure variable Filled with queue alert data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatCaviumPtQueuePktData)(uint32_t devId, telAgentPtQueueInfo ptQueueData,
            char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in ptPortData
     *   this API will Fill message with data of PT for port
     *
     * @param devId          - [in] device id
     * @param ptPortData     - [in] structure of port data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatCaviumPtPortPktData)(uint32_t devId, telAgentPtPortInfo ptPortData,
            char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in tableConfig
     *   this API will Fill message with configuration details of table
     *
     * @param devId          - [in] device id
     * @param tableTotal     - [in] total table
     * @param tableConfig    - [in] structure variable Filled with table configuration data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatTableConfig)(uint32_t devId, uint8_t tableTotal,
            telAgentTableConfig* tableConfig, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in tableStat
     *   this API will Fill message with configuration details of table.
     *
     * @param devId          - [in] device id
     * @param tableTotal     - [in] total table
     * @param tableStat      - [in] structure variable Filled with table data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatFlowDataMetrics)(uint32_t devId, uint8_t tableTotal,
            telAgentTableFlowMetrics* tableStat, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with defined message format of PD.
     *
     * @param devId          - [in] device id
     * @param pktInfo        - [in] packet info
     * @param pktSize        - [in] packet size
     * @param pktData        - [in] packet data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatPacketDissectorPKtData)(uint32_t devId, telAgentPktInfo pktInfo,
            uint16_t pktSize, uint8_t* pktData, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with defined message format of Exception monitoring
     *
     * @param devId          - [in] device id
     * @param pktInfo        - [in] packet info
     * @param pktSize        - [in] packet size
     * @param pktData        - [in] packet data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatExceptionMonitoringPktData)(uint32_t devId, telAgentPktInfo pktInfo,
            uint16_t pktSize, uint8_t* pktData, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with appropriate message for temperature
     *
     * @param devId          - [in] device id
     * @param temp           - [in] temperature
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatTemperature)(uint32_t devId, float temp, char* msgPayload,
            uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with appropriate message for cpu load
     *
     * @param devId          - [in] device id
     * @param cpuLoad        - [in] current CPU load
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatCpuLoad)(uint32_t devId, float cpuLoad, char* msgPayload,
                                            uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with data specified in registerInfo
     *
     * @param devId          - [in] device id
     * @param devType        - [in] Device type
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatRegisterDevice)(uint32_t devId, telAgentDeviceType devType,
            char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill msgPayload with message format of heartbeat
     *
     * @param devId          - [in] device id
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatHeartBeatAlive)(uint32_t devId, char* msgPayload, uint16_t* msgLength);

    /**
     * @brief Fill message for Port ditribution
     *
     * @param devId          - [in] device id
     * @param destPort       - [in] destination port
     * @param pktCount       - [in] packet count
     * @param srcPortCount   - [in] source port count
     * @param data           - [in] structure pointer for source port data
     * @param msgPayload     - [out] message string
     * @param msgLength      - [in/out] maximum payload length(in), length of payload after message formation(out)
     *
     * @return AGENT_NO_ERR - success
     */
    AGENT_STATUS(*telAgentMsgFormatPortDistribution)(uint32_t devId, uint8_t destPort,
            uint32_t pktCount, uint8_t srcPortCount, telAgentSourcePortData* data,
            char* msgPayload, uint16_t* msgLength);
} telAgentMsgFormatWrapperFunctions;

/**
* @brief This API is expected to assign communication and message formation APIs
*       to agentCommWrapperApis and agentMsgFormatWrapperApis, respectively.
*
*       Also save the information of switch used for registration in cloud adapter,
*       which are passed in regInfo.
*
* @param regInfo                    - [in] registeration info
* @param agentCommWrapperApis       - [out] cloud adapter communication API function pointer
* @param agentMsgFormatWrapperApis  - [out] cloud adapter message formate API function pointer
*
* @return AGENT_NO_ERR - success
*/
AGENT_STATUS telAgentcloudAdapterInit(telAgentSwitchRegisterInfo regInfo,
                                      telAgentCommWrapperFunctions *agentCommWrapperApis,
                                      telAgentMsgFormatWrapperFunctions *agentMsgFormatWrapperApis);

#endif //AGENTCLOUDWRAPPER_H
