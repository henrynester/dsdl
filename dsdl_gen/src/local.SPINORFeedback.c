#define CANARD_DSDLC_INTERNAL
#include <local.SPINORFeedback.h>
#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t local_SPINORFeedback_encode(struct local_SPINORFeedback* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, LOCAL_SPINORFEEDBACK_MAX_SIZE);
    _local_SPINORFeedback_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

/*
  return true if the decode is invalid
 */
bool local_SPINORFeedback_decode(const CanardRxTransfer* transfer, struct local_SPINORFeedback* msg) {
#if CANARD_ENABLE_TAO_OPTION
    if (transfer->tao && (transfer->payload_len > LOCAL_SPINORFEEDBACK_MAX_SIZE)) {
        return true; /* invalid payload length */
    }
#endif
    uint32_t bit_ofs = 0;
    if (_local_SPINORFeedback_decode(transfer, &bit_ofs, msg,
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    )) {
        return true; /* invalid payload */
    }

    const uint32_t byte_len = (bit_ofs+7U)/8U;
#if CANARD_ENABLE_TAO_OPTION
    // if this could be CANFD then the dlc could indicating more bytes than
    // we actually have
    if (!transfer->tao) {
        return byte_len > transfer->payload_len;
    }
#endif
    return byte_len != transfer->payload_len;
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORFeedback sample_local_SPINORFeedback_msg(void) {
    struct local_SPINORFeedback msg;

    msg.position = random_float_val();
    msg.velocity = random_float_val();
    msg.torque = random_float_val();
    return msg;
}
#endif
