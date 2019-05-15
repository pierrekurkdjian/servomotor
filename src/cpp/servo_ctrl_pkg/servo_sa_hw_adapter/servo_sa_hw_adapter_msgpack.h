#ifndef _servo_sa_hw_adapter_msgpack_h_
#define _servo_sa_hw_adapter_msgpack_h_

#include <msgpack.hpp>
#include "ocs_core_fwk.h"
#include "ocs_io_fwk.h"
#include "../../include/servo_dcs_port_types.h"

struct servoSaHwAdapterSetup : public  EthercatAdapterSetup {

    struct PropertyConf : public  EthercatAdapterSetup::PropertyConf {
        MSGPACK_DEFINE_MAP(uri, name, host, port, scan_rate, acl)
    };

    struct StateVarConf : public  EthercatAdapterSetup::StateVarConf {
        MSGPACK_DEFINE_MAP(ops_state)
    };

    struct InputPortConf : public EthercatAdapterSetup::InputPortConf {
        PortDef<uint16_t>               motor_state_goal;    //Erika
        PortDef<uint16_t>               motor_velocity_goal; //Erika
        MSGPACK_DEFINE_MAP(motor_state_goal, motor_velocity_goal, /*date_write,*/ /*enable, close_loop_hw_ad, pwm_offset_hw_ad, force_sp_hw_ad, msthb_hw_ad,*/ sdo_write_enable, sdo_read_update_req, ecat_bus, ops_state_goal)
    };                                                                                              //Pierre2

    struct OutputPortConf : public EthercatAdapterSetup::OutputPortConf {
        // PortDef<uint16_t>               motor_state_value;    //Erika
        // PortDef<uint16_t>               motor_velocity_value; //Erika
        // PortDef<uint16_t>               motor_position_value; //Erika
        MSGPACK_DEFINE_MAP(/*motor_state_value, motor_velocity_value, motor_position_value,*/ /*date_read,*/ /*enable_check, close_loop_status, err_hw_ad, force_rb, force_sp_status, pwm_status, slvhb_hw_ad,*/ sdo_read_update_done, heartbeat_out, ops_state_value)
    };                                                                                                                      //Pierre2

    PropertyConf     properties;
    StateVarConf     state_vars;
    InputPortConf    input_ports;
    OutputPortConf   output_ports;

    MSGPACK_DEFINE_MAP(properties, state_vars, input_ports, output_ports)
};

#endif // _servo_sa_hw_adapter_msgpack_h_
