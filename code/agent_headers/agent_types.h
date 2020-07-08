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
 * Author - Aalok Shah
 * Date - March-2018
 ************************************************************************/
/**
 * \file agentTypes.h
 * \brief
 */

#ifndef AGENTTYPES_H
#define AGENTTYPES_H

/*******************
 * Includes
 *******************/
#include <inttypes.h>

/*********************
* Structures and Enum
***********************/
#define CAVIUM_QUEUE_COUNT_FOR_PT_PACKET        16   ///< CAVIUM_QUEUE_COUNT_FOR_PT_PACKET
#define CAVIUM_BUFFER_COUNT_PER_PORT_PAGE_SIZE   256 ///< CAVIUM_BUFFER_COUNT_PER_PORT_PAGE_SIZE
#define AGENT_DEVICE_MAC_ADDR_SIZE            20           ///< DEVICE_MAC_ADDR_SIZE

/* Default config file: Agent will check for this file in current executing directory */
#define DEFAULT_CONFIG_FILE     "agentConfig.txt"       ///< DEFAULT_CONFIG_FILE

typedef enum telAgentDeviceType
{
    CAVIUM_XP80,            ///< 0 - Cavium XP80 device
    CAVIUM_XP80B0,          ///< 1 - Cavium XP80B0 device
    CAVIUM_XP70,            ///< 2 - Cavium XP70 device
    CAVIUM_XP70A1,          ///< 3 - Cavium XP70A1 device
    CAVIUM_XP70A2,          ///< 4 - Cavium XP70A2 device
    CAVIUM_XPT,             ///< 5 - Cavium XPT device
    AGENT_DEV_TYPE_TOTAL    ///< 6 - Total device supported in agent
} telAgentDeviceType;

typedef enum telAgentTableList
{
    FDB_TABLE,                  ///< 0 - FDB table
    IPV4_HOST_TABLE,            ///< 1 - IPV4 host table
    IPV6_HOST_TABLE,            ///< 2 - IPV6 host table
    IPV4_BRIDGEMC_TABLE,        ///< 3 - IPV4 bridge MC table
    IPV6_BRIDGEMC_TABLE,        ///< 4 - IPV6 bridge MC table
    IPV4_ROUTEMC_TABLE,         ///< 5 - IPV4 route MC table
    IPV6_ROUTEMC_TABLE,         ///< 6 - IPV6 route MC table
    MPLS_LABEL_TABLE,           ///< 7 - MPLS label table
    PORT_VLAN_TABLE,            ///< 8 - Port VLAN table
    NEXT_HOP_TABLE,             ///< 9 - Next hop table
    MPLS_TUNNEL_TABLE,          ///< 10 - MPLS tunnel table
    EGRESS_BD_TABLE,            ///< 11 - Egress BD table
    NAT_IPV4_TABLE,             ///< 12 - NAT IPV4 table
    IPV4_PIM_TABLE,             ///< 13 - IPV4 PIM table
    IPV4_IPV6_ROUTE_TABLE,      ///< 14 - IPV4/IPv6 route table
    AGENT_MAX_TABLE_SUPPORTED   ///< 15 - Max supported tables
} telAgentTableList;

typedef enum telAgentPacketTrap
{
    START_PACKET_TRAP,          ///< 0 - start trapping of packet for PD
    STOP_PACKET_TRAP            ///< 1 - stop trapping of packet for PD
} telAgentPacketTrap;

typedef enum telAgentRetStatus
{
    AGENT_NO_ERR,                       ///< 0 - No error
    AGENT_ERR_ATTR_NOT_FOUND,           ///< 1 - Attribute not found
    AGENT_ERR_COMM_CLOUD,               ///< 2 - Error while communicating with cloud adapter
    AGENT_ERR_COMM_SDK,                 ///< 3 - Error while communicating with SDK adapter
    AGENT_ERR_FEATURE_EXISTS,           ///< 4 - Feature already exists
    AGENT_ERR_IOCTL_FAIL,               ///< 5 - IOCTL failed
    AGENT_ERR_INFO_NOT_FOUND,           ///< 6 - Info not found for
    AGENT_ERR_INIT,                     ///< 7 - Error in initialization
    AGENT_ERR_DEINIT,                   ///< 8 - Error in deinitialization
    AGENT_ERR_INVALID_INPUT,            ///< 9 - Invalid input passed
    AGENT_ERR_MEM_ALLOC,                ///< 10 - Error while allocating memory
    AGENT_ERR_COMM_CHANNEL,             ///< 11 - Error in connecting with server
    AGENT_ERR_NULL_PTR,                 ///< 12 - Null pointer found
    AGENT_ERR_NOT_SUPPORT,              ///< 13 - Attribute/Value not supported
    AGENT_ERR_REGISTER_FAIL,            ///< 14 - Registration failed
    AGENT_ERR_SAL_CALL_FAIL,            ///< 15 - Sal call failed
    AGENT_ERR_SOCKET_INIT,              ///< 16 - Socket init failed
    AGENT_ERR_THREAD_EXISTS,            ///< 17 - Tring to create thread which already exists
    AGENT_ERR_THREAD_DOES_NOT_EXIST,    ///< 18 - Thread does not exists
    AGENT_ERR_SEND_MSG,                 ///< 19 - Error in sending message to the server
    AGENT_ERR_WRITE_CONFIG,             ///< 20 - Error in writing configuration in SDK adapter
    AGENT_ERR_MEM_CORRUPTION,           ///< 21 - Memory corruption
    AGENT_ERR_INVALID_ATRIBUTE_TYPE,    ///< 22 - Invalid attribute passed
    AGENT_ERR_CLIENT_INIT,              ///< 23 - Failed to create client for server
    AGENT_ERR_UNKNOWN_DEVICE,           ///< 24 - Unknown device found
    AGENT_ERR_SYSTEM_API_FAILED,        ///< 25 - System call failed
    AGENT_ERR_DEVICE_NOT_INITED,        ///< 26 - Device is not initialized
    AGENT_ERR_UNSUPPORTED_REASON_CODE,  ///< 27 - Reason code is not supported
    AGENT_ERR_UNSUPPORTED_FEATURE,      ///< 28 - Feature is not supported
    AGENT_ERR_CONFIG_NOT_FOUND,         ///< 29 - Configuration not found
    AGENT_ERR_THREAD_RUNNING,           ///< 30 - Thread is running
    AGENT_ERR_NOT_IMPLEMENTED,		///< 31 - API is not found / empty (used for OS specific APIs)
    AGENT_MAX_RET_VALUE                 ///< 32 - Maximum return value
} AGENT_STATUS;

typedef enum telAgentReasonCode
{
    AGENT_RC_PKT_TYPE_UNKNOWN,          ///< 0 - Invalid Header or Packet Type Mismatch
    AGENT_RC_ROUTE_NOT_POSSIBLE,        ///< 1 - Route Table Miss
    AGENT_RC_ROUTE_MC_NOT_POSSIBLE,     ///< 2 - Multicast Route Table Miss
    AGENT_RC_ROUTE_MC_INVALID_DA,       ///< 3 - Multicast Packet Mismatch [Incorrect MAC Address]
    AGENT_RC_ROUTE_MC_RPF_FAIL,         ///< 4 - Multicast Reverse Path Forwarding Fail
    AGENT_RC_ROUTE_IP_OPTIONS,          ///< 5 - IP Options Available
    AGENT_RC_ROUTE_URPF_FAIL,           ///< 6 - Unicast Reverse Path Forwarding Fail
    AGENT_RC_NAT_TABLE_MISS,            ///< 7 - NAT Table MIss
    AGENT_RC_MTU_LIMIT_EXCEEDED,        ///< 8 - MTU Limit Exceeded
    AGENT_RC_PORT_VLAN_MISS,            ///< 9 - Port to Vlan Config Mismatch
    AGENT_RC_PORT_TAG_POLICY,           ///< 10 - Port Tag Policy Not Hit
    AGENT_RC_TNL_ID_MISS,               ///< 11 - Tunnel Table Miss
    AGENT_RC_SPAN_BLOCKED,              ///< 12 - STP State Blocked
    AGENT_RC_INT_PKT,                   ///< 13 - INT packet
    AGENT_RC_PT_PKT,                    ///< 14 - Packet tracker packet
    AGENT_RC_PD_PKT,                    ///< 15 - Packet dissector packet
    AGENT_MAX_REASON_CODE               ///< 16 - Maximum reason code supported
} telAgentReasonCode;

typedef struct telAgentPktInfo
{
    uint32_t    ingressVif;             ///< Ingress Vif
    uint32_t    ingressPortNum;         ///< Ingress port number
    uint8_t     tunnelTerminateFlag;    ///< Tunnel terminate flag
    uint64_t    pktRecvTimeStamp;       ///< Timestamp
    uint32_t    devId;                  ///< device Id
    telAgentReasonCode reasonCode;      ///< Reason code
} telAgentPktInfo;

typedef struct telAgentPortStatistics
{
    uint64_t rxTotal;           ///< Number of packets received on port
    uint64_t rxGoodCount;       ///< rxGoodCount
    uint64_t rxBadCount;        ///< rxBadCount
    uint64_t rxFcsError;        ///< rxFcsError
    uint64_t rxLengthError;     ///< rxLengthError
    uint64_t rxUcCount;         ///< rxUcCount
    uint64_t rxMcCount;         ///< rxMcCount
    uint64_t rxBcCount;         ///< rxBcCount
    uint64_t rxUndersizeCount;      ///< rxUndersizeCount
    uint64_t rxOversizeCount;       ///< rxOversizeCount
    uint64_t rxPauseCount;      ///< rxPauseCount
    uint64_t rxFifoFullDrop;        ///< rxFifoFullDrop
    uint64_t rxFrag;            ///< rxFrag
    uint64_t rxJabberFrag;      ///< rxJabberFrag
    uint64_t txTotal;           ///< txTotal
    uint64_t txGoodCount;       ///< txGoodCount
    uint64_t txBadCount;        ///< txBadCount
    uint64_t txUcCount;         ///< txUcCount
    uint64_t txMcCount;         ///< txMcCount
    uint64_t txBcCount;         ///< txBcCount;
    uint64_t txPauseCount;      ///< txPauseCount
} telAgentPortStatistics;

typedef struct telAgentTableConfig
{
    uint32_t tableId;       ///< Table id
    char tableName[50];     ///< Table name
    uint32_t tableDepth;    ///< Maximum depth of table
    uint32_t tableWidth;    ///< Maximum width of table
} telAgentTableConfig;

typedef struct telAgentTableFlowMetrics
{
    uint32_t tableId;           ///< Table id
    uint32_t tableCurDepth;     ///< Current depth of table
    uint32_t tableTotalDepth;   ///< Maximum depth of table
} telAgentTableFlowMetrics;

typedef struct telAgentQueueStatistics
{
    uint8_t qId;            ///< Queue id
    char qType[15];         ///< Queue type
    uint32_t capacity;      ///< Maximum capacity of queue
    uint32_t currentLoad;   ///< Current load of queue
    uint64_t dropCount;     ///< Drop count of queue
} telAgentQueueStatistics;

typedef struct telAgentBufferStatstics
{
    uint32_t totalBuffer;   ///< Total capacity of buffer
    uint32_t currentBuffer; ///< Current occupancy of buffer
} telAgentBufferStatstics;

typedef struct telAgentPtQueueInfo
{
    uint16_t switchId;          ///< Switch id
    uint64_t timestamp;         ///< Timestamp of switch
    uint8_t srcPort;            ///< Source port number
    uint8_t dstPort;            ///< Destination port number
    uint16_t queueDynMaxTh;     ///< Value of queue dynamic maximum threshold
    uint32_t queueAvgWm;        ///< Value of queue average watermark
    uint32_t queueWm;           ///< Value of queue watermark
    uint8_t totalMaxThStat;     ///< Max threshold status
    uint8_t totalMcMaxThStat;   ///< MC max threshold status
} telAgentPtQueueInfo;

typedef struct telAgentPtPortInfo
{
    uint16_t switchId;          ///< Switch id
    uint64_t timestamp;         ///< Timestamp of switch
    uint8_t srcPort;            ///< Source port number
    uint8_t dstPort;            ///< Destination port number
    uint8_t portMaxth;          ///< Value of port max threshold
    uint8_t totalMaxThStat;     ///< Max threshold status
    uint8_t totalMcMaxThStat;   ///< MC max threshold status
} telAgentPtPortInfo;

//SwitchId, IngressPort, egressPort - Fixed Metadata Considered
typedef union telAgentIntOptMetaFlags
{
    uint8_t intOptMetaFlags;        ///< INT flags

    /* This structure is to identify which field is active
     * Only any one of this can be selected at a time */
    struct intOptMetaBit
    {
        uint8_t inTimestamp: 1;             ///< Ingress Timestamp
        uint8_t hopLatency: 1;              ///< Hop latency
        uint8_t queueCongestion: 1;             ///< Queue congestion
        uint8_t egressPortTxUtilization: 1;     ///< Egress port transmission utilization
        uint8_t pathLatency: 1;             ///< Path latency from last node
        uint8_t queueOccupancy: 1;          ///< Queue occupance
        uint8_t reserved: 2;                ///< Reserved
    } optMetaBits;		///< Selection of metadata
} telAgentIntOptMetaFlags;

typedef struct telAgentIntSwitchInfo
{
    uint8_t index;                  ///< Index of switch with refrence to sink node
    uint32_t switchId;              ///< Switch Id
    uint32_t ingressVif;            ///< Ingress Vif
    uint32_t egressVif;             ///< Egress Vif
    uint32_t ingressPort;           ///< Ingress port number
    uint32_t egressPort;            ///< Egress port number
    uint32_t ingressTimestamp;      ///< Ingress Timestamp
    uint32_t queueCongestion;       ///< Queue congestion
    uint32_t hopLatency;            ///< Hop latency
    uint32_t egressPortTxUtilization;   ///< Egress port transmission utilization
    uint32_t queueOccupancy;        ///< Queue occupance
    uint32_t pathLatency;           ///< Path latency from last node
} telAgentIntSwitchInfo;

typedef struct telAgentSwitchRegisterInfo
{
    char macAddr[AGENT_DEVICE_MAC_ADDR_SIZE];   ///< MAC Address
    uint8_t agentAsIntCollector;       ///< Flag for INT Collector
} telAgentSwitchRegisterInfo;

typedef struct telAgentSourcePortData
{
    uint8_t     srcPort;    ///< Source port number
    uint8_t     qNum;       ///< Queue number
    uint32_t    pktCount;   ///< Count of received packet for srcPort
} telAgentSourcePortData;

#endif //AGENTTYPES_H
