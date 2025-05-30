#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define LOCAL_SPINORSTATUS_MAX_SIZE 9
#define LOCAL_SPINORSTATUS_SIGNATURE (0xFC31DE9ECABC5804ULL)
#define LOCAL_SPINORSTATUS_ID 20110

#define LOCAL_SPINORSTATUS_ERROR_OK 0
#define LOCAL_SPINORSTATUS_ERROR_COMMAND_TIMEOUT 1
#define LOCAL_SPINORSTATUS_ERROR_FOC_DEADLINE_MISSED 2
#define LOCAL_SPINORSTATUS_ERROR_POS_VEL_DEADLINE_MISSED 3
#define LOCAL_SPINORSTATUS_ERROR_IABC_HIGH 4
#define LOCAL_SPINORSTATUS_ERROR_VBUS_LOW 5
#define LOCAL_SPINORSTATUS_ERROR_VBUS_HIGH 6
#define LOCAL_SPINORSTATUS_ERROR_TMTR_HIGH 7
#define LOCAL_SPINORSTATUS_ERROR_TFET_HIGH 8
#define LOCAL_SPINORSTATUS_ERROR_VEL_HIGH 9
#define LOCAL_SPINORSTATUS_ERROR_ENCODER 10

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class local_SPINORStatus_cxx_iface;
#endif

struct local_SPINORStatus {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = local_SPINORStatus_cxx_iface;
#endif
    bool armed;
    uint8_t error;
    float v_bus;
    uint8_t T_mtr;
    uint8_t T_fet;
    uint8_t foc_deadline_perc;
    uint8_t controller_cpu_perc;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_SPINORStatus_encode(struct local_SPINORStatus* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_SPINORStatus_decode(const CanardRxTransfer* transfer, struct local_SPINORStatus* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_SPINORStatus_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORStatus* msg, bool tao);
static inline bool _local_SPINORStatus_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORStatus* msg, bool tao);
void _local_SPINORStatus_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORStatus* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->armed);
    *bit_ofs += 1;
    canardEncodeScalar(buffer, *bit_ofs, 7, &msg->error);
    *bit_ofs += 7;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->v_bus);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->T_mtr);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->T_fet);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->foc_deadline_perc);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->controller_cpu_perc);
    *bit_ofs += 8;
}

/*
 decode local_SPINORStatus, return true on failure, false on success
*/
bool _local_SPINORStatus_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORStatus* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->armed);
    *bit_ofs += 1;

    canardDecodeScalar(transfer, *bit_ofs, 7, false, &msg->error);
    *bit_ofs += 7;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->v_bus);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->T_mtr);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->T_fet);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->foc_deadline_perc);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->controller_cpu_perc);
    *bit_ofs += 8;

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORStatus sample_local_SPINORStatus_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(local_SPINORStatus, LOCAL_SPINORSTATUS_ID, LOCAL_SPINORSTATUS_SIGNATURE, LOCAL_SPINORSTATUS_MAX_SIZE);
#endif
#endif
