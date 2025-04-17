#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define LOCAL_HELLOWORLD_MAX_SIZE 7
#define LOCAL_HELLOWORLD_SIGNATURE (0xDA542AF454525FD5ULL)
#define LOCAL_HELLOWORLD_ID 12

#define LOCAL_HELLOWORLD_MAX_BROADCASTING_PERIOD_MS 1000
#define LOCAL_HELLOWORLD_MIN_BROADCASTING_PERIOD_MS 2
#define LOCAL_HELLOWORLD_OFFLINE_TIMEOUT_MS 3000
#define LOCAL_HELLOWORLD_HEALTH_OK 0
#define LOCAL_HELLOWORLD_HEALTH_WARNING 1
#define LOCAL_HELLOWORLD_HEALTH_ERROR 2
#define LOCAL_HELLOWORLD_HEALTH_CRITICAL 3
#define LOCAL_HELLOWORLD_MODE_OPERATIONAL 0
#define LOCAL_HELLOWORLD_MODE_INITIALIZATION 1
#define LOCAL_HELLOWORLD_MODE_MAINTENANCE 2
#define LOCAL_HELLOWORLD_MODE_SOFTWARE_UPDATE 3
#define LOCAL_HELLOWORLD_MODE_OFFLINE 7

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class local_HelloWorld_cxx_iface;
#endif

struct local_HelloWorld {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = local_HelloWorld_cxx_iface;
#endif
    uint32_t uptime_sec;
    uint8_t health;
    uint8_t mode;
    uint8_t sub_mode;
    uint16_t vendor_specific_status_code;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_HelloWorld_encode(struct local_HelloWorld* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_HelloWorld_decode(const CanardRxTransfer* transfer, struct local_HelloWorld* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_HelloWorld_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_HelloWorld* msg, bool tao);
static inline bool _local_HelloWorld_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_HelloWorld* msg, bool tao);
void _local_HelloWorld_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_HelloWorld* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->uptime_sec);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 2, &msg->health);
    *bit_ofs += 2;
    canardEncodeScalar(buffer, *bit_ofs, 3, &msg->mode);
    *bit_ofs += 3;
    canardEncodeScalar(buffer, *bit_ofs, 3, &msg->sub_mode);
    *bit_ofs += 3;
    canardEncodeScalar(buffer, *bit_ofs, 16, &msg->vendor_specific_status_code);
    *bit_ofs += 16;
}

/*
 decode local_HelloWorld, return true on failure, false on success
*/
bool _local_HelloWorld_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_HelloWorld* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    canardDecodeScalar(transfer, *bit_ofs, 32, false, &msg->uptime_sec);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 2, false, &msg->health);
    *bit_ofs += 2;

    canardDecodeScalar(transfer, *bit_ofs, 3, false, &msg->mode);
    *bit_ofs += 3;

    canardDecodeScalar(transfer, *bit_ofs, 3, false, &msg->sub_mode);
    *bit_ofs += 3;

    canardDecodeScalar(transfer, *bit_ofs, 16, false, &msg->vendor_specific_status_code);
    *bit_ofs += 16;

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_HelloWorld sample_local_HelloWorld_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(local_HelloWorld, LOCAL_HELLOWORLD_ID, LOCAL_HELLOWORLD_SIGNATURE, LOCAL_HELLOWORLD_MAX_SIZE);
#endif
#endif
