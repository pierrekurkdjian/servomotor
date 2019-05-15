#include "servo_sa_hw_adapter.h"
#include "servo_sa_hw_adapter_msgpack.h"

using namespace gmt;

void servoSaHwAdapter::create_config() {

    Setup* the_config = new Setup;
    config = the_config;

    setup_port = create_port(*the_config, "setup_port", "pull", url, "async", scan_rate, scan_rate);
    log_info("Setup port created: "+url);
}

void servoSaHwAdapter::setup() {
    std::cout << "1 servoSaHwAdapter::setup()" << std::endl;
    Setup::InputPortConf&  inputp_confs   = dynamic_cast<Setup*>(config)->input_ports;
    std::cout << "2 servoSaHwAdapter::setup()" << std::endl;
    Setup::OutputPortConf& outputp_confs  = dynamic_cast<Setup*>(config)->output_ports;
    std::cout << "3 servoSaHwAdapter::setup()" << std::endl;
    Setup::PropertyConf&   property_confs = dynamic_cast<Setup*>(config)->properties;

    log_info("port setup");

    // create input ports
    // new_input_port(enable,                    "enable",                inputp_confs.enable);
    // new_input_port(close_loop_hw_ad,          "close_loop_hw_ad",      inputp_confs.close_loop_hw_ad);
    // new_input_port(pwm_offset_hw_ad,          "pwm_offset_hw_ad",      inputp_confs.pwm_offset_hw_ad);
    // new_input_port(force_sp_hw_ad,            "force_sp_hw_ad",        inputp_confs.force_sp_hw_ad);
    // new_input_port(msthb_hw_ad,               "msthb_hw_ad",           inputp_confs.msthb_hw_ad);
    new_input_port(ecat_bus,                  "ecat_bus",              inputp_confs.ecat_bus);
    new_input_port(sdo_read_update_req,       "sdo_read_update_req",   inputp_confs.sdo_read_update_req);   //Pierre2
    new_input_port(sdo_write_enable,          "sdo_write_enable",      inputp_confs.sdo_write_enable);   //Pierre2
    //new_input_port(date_write_string,         "date_write_string",     inputp_confs.date_write_string);   //Pierre2
    //new_input_port(date_write,                "date_write",            inputp_confs.date_write);   //Pierre2

    // create output ports
    // new_output_port(enable_check,             "enable_check",          outputp_confs.enable_check);
    // new_output_port(close_loop_status,        "close_loop_status",     outputp_confs.close_loop_status);
    // new_output_port(err_hw_ad,                "err_hw_ad",             outputp_confs.err_hw_ad);
    // new_output_port(force_rb,                 "force_rb",              outputp_confs.force_rb);
    // new_output_port(force_sp_status,          "force_sp_status",       outputp_confs.force_sp_status);
    // new_output_port(pwm_status,               "pwm_status",            outputp_confs.pwm_status);
    // new_output_port(slvhb_hw_ad,              "slvhb_hw_ad",           outputp_confs.slvhb_hw_ad);
    // new_output_port(heartbeat_out,            "heartbeat_out",         outputp_confs.heartbeat_out);
    new_output_port(sdo_read_update_done,     "sdo_read_update_done",  outputp_confs.sdo_read_update_done);   //Pierre2
    //
    // // Create state variable ports  (current, goal, health)
    // new_input_port(ops_state_sv.goal,         "ops_state_goal",        inputp_confs.ops_state_goal);
    // new_output_port(ops_state_sv.value,       "ops_state_value",       outputp_confs.ops_state_value);
    //
    // new_input_port(motor_state_goal,         "motor_state_goal",        inputp_confs.motor_state_goal);
    // new_input_port(motor_velocity_goal,      "motor_velocity_goal",     inputp_confs.motor_velocity_goal);
    // new_output_port(motor_state_value,       "motor_state_value",       outputp_confs.motor_state_value);
    // new_output_port(motor_velocity_value,    "motor_velocity_value",    outputp_confs.motor_velocity_value);
    // new_output_port(motor_position_value,    "motor_position_value",    outputp_confs.motor_position_value);
std::cout << "ici" << std::endl;

    new_input_port(motor_state_goal,         "motor_state_goal",        inputp_confs.motor_state_goal);
    new_input_port(motor_velocity_goal,      "motor_velocity_goal",     inputp_confs.motor_velocity_goal);
    // new_output_port(motor_state_value,       "motor_state_value",       outputp_confs.motor_state_value);
    // new_output_port(motor_velocity_value,    "motor_velocity_value",    outputp_confs.motor_velocity_value);
    // new_output_port(motor_position_value,    "motor_position_value",    outputp_confs.motor_position_value);
std::cout << "ici bis" << std::endl;

    // Create properties
    new_property(uri,                         "uri",                   property_confs.uri);
    new_property(name,                        "name",                  property_confs.name);
    new_property(host,                        "host",                  property_confs.host);
    new_property(port,                        "port",                  property_confs.port);
    new_property(scan_rate,                   "scan_rate",             property_confs.scan_rate);
    new_property(acl,                         "acl",                   property_confs.acl);
std::cout << "la" << std::endl;
    set_fieldbus_config_port(ecat_bus, "ecat_bus");
std::cout << "ba" << std::endl;
    // create data_object references
    // create_data_object_ref(enable[0],                               "sa1_enable");
    // create_data_object_ref(close_loop_hw_ad[0],                     "sa1_close_loop");
    // create_data_object_ref(pwm_offset_hw_ad[0],                     "sa1_pwm_offset");
    // create_data_object_ref(force_sp_hw_ad.X[0],                     "sa1_force_sp_X");
    // create_data_object_ref(force_sp_hw_ad.Y[0],                     "sa1_force_sp_Y");
    // create_data_object_ref(force_sp_hw_ad.Z[0],                     "sa1_force_sp_Z");
    // create_data_object_ref(msthb_hw_ad[0],                          "sa1_msthb");
    // create_data_object_ref(enable_check[0],                         "sa1_chk_enable");
    // create_data_object_ref(close_loop_status[0],                    "sa1_close_loop_pdo");
    // create_data_object_ref(err_hw_ad.err_force_minmax[0],           "sa1_err_force_minmax");
    // create_data_object_ref(err_hw_ad.err_force_step[0],             "sa1_err_force_step");
    // create_data_object_ref(err_hw_ad.err_follow_error[0],           "sa1_err_follow_error");
    // create_data_object_ref(err_hw_ad.err_calibrated[0],             "sa1_err_calibrated");
    // create_data_object_ref(err_hw_ad.err_masterhb[0],               "sa1_err_masterhb");
    // create_data_object_ref(err_hw_ad.err_io[0],                     "sa1_err_io");
    // create_data_object_ref(err_hw_ad.err_soc[0],                    "sa1_err_soc");
    // create_data_object_ref(err_hw_ad.err_dongle[0],                 "sa1_err_dongle");
    // create_data_object_ref(force_rb.X[0],                           "sa1_force_rb_X");
    // create_data_object_ref(force_rb.Y[0],                           "sa1_force_rb_Y");
    // create_data_object_ref(force_rb.Z[0],                           "sa1_force_rb_Z");
    // create_data_object_ref(force_sp_status.X[0],                    "sa1_chk_force_sp_X");
    // create_data_object_ref(force_sp_status.Y[0],                    "sa1_chk_force_sp_Y");
    // create_data_object_ref(force_sp_status.Z[0],                    "sa1_chk_force_sp_Z");
    // create_data_object_ref(pwm_status.pwservo[0],                      "sa1_pwservo");
    // create_data_object_ref(pwm_status.pwm2[0],                      "sa1_pwm2");
    // create_data_object_ref(pwm_status.pwm3[0],                      "sa1_pwm3");
    // create_data_object_ref(slvhb_hw_ad[0],                          "sa1_slvhb");
    // create_data_object_ref(enable[1],                               "sa2_enable");
    // create_data_object_ref(close_loop_hw_ad[1],                     "sa2_close_loop");
    // create_data_object_ref(pwm_offset_hw_ad[1],                     "sa2_pwm_offset");
    // create_data_object_ref(force_sp_hw_ad.X[1],                     "sa2_force_sp_X");
    // create_data_object_ref(force_sp_hw_ad.Y[1],                     "sa2_force_sp_Y");
    // create_data_object_ref(force_sp_hw_ad.Z[1],                     "sa2_force_sp_Z");
    // create_data_object_ref(msthb_hw_ad[1],                          "sa2_msthb");
    // create_data_object_ref(enable_check[1],                         "sa2_chk_enable");
    // create_data_object_ref(close_loop_status[1],                    "sa2_close_loop_pdo");
    // create_data_object_ref(err_hw_ad.err_force_minmax[1],           "sa2_err_force_minmax");
    // create_data_object_ref(err_hw_ad.err_force_step[1],             "sa2_err_force_step");
    // create_data_object_ref(err_hw_ad.err_follow_error[1],           "sa2_err_follow_error");
    // create_data_object_ref(err_hw_ad.err_calibrated[1],             "sa2_err_calibrated");
    // create_data_object_ref(err_hw_ad.err_masterhb[1],               "sa2_err_masterhb");
    // create_data_object_ref(err_hw_ad.err_io[1],                     "sa2_err_io");
    // create_data_object_ref(err_hw_ad.err_soc[1],                    "sa2_err_soc");
    // create_data_object_ref(err_hw_ad.err_dongle[1],                 "sa2_err_dongle");
    // create_data_object_ref(force_rb.X[1],                           "sa2_force_rb_X");
    // create_data_object_ref(force_rb.Y[1],                           "sa2_force_rb_Y");
    // create_data_object_ref(force_rb.Z[1],                           "sa2_force_rb_Z");
    // create_data_object_ref(force_sp_status.X[1],                    "sa2_chk_force_sp_X");
    // create_data_object_ref(force_sp_status.Y[1],                    "sa2_chk_force_sp_Y");
    // create_data_object_ref(force_sp_status.Z[1],                    "sa2_chk_force_sp_Z");
    // create_data_object_ref(pwm_status.pwservo[1],                      "sa2_pwservo");
    // create_data_object_ref(pwm_status.pwm2[1],                      "sa2_pwm2");
    // create_data_object_ref(pwm_status.pwm3[1],                      "sa2_pwm3");
    // create_data_object_ref(slvhb_hw_ad[1],                          "sa2_slvhb");

    // Add transport definition of port types related to state variables

    // create_data_object_ref(date_write,                        "date_write");
    // create_data_object_ref(date_read,                         "date_read");
    create_data_object_ref(motor_state_goal,                        "control_word");
    create_data_object_ref(motor_state_value,                       "status_word");

    create_data_object_ref(motor_velocity_goal,                     "target_velocity");
    create_data_object_ref(motor_velocity_value,                    "actual_velocity");

    create_data_object_ref(motor_position_value,                    "position");

    // create_data_object_ref(motor_velocity_goal,                     "target_velocity");
    // create_data_object_ref(motor_velocity_value,                    "actual_velocity");
    //
    // create_data_object_ref(motor_position_value,                    "position");

}
