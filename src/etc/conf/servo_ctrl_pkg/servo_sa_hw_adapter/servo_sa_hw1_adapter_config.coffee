
# Component  servo_sa_hw1_adapter instance configuration file
# Ports should be setup per instance

module.exports =

    properties:
        uri: { name: 'uri', default_value: 'gmt://servo_dcs/servo_sa_hw_adapter/servo_sa_hw1_adapter' , type: 'String', desc: 'Uri path for the component' }
        name: { name: 'name', default_value: 'servo_sa_hw_adapter' , type: 'String', desc: 'Name the component' }
        host: { name: 'host', default_value: '127.0.0.1' , type: 'String', desc: 'Default host for deployment.' }
        port: { name: 'port', default_value: 10012 , type: 'Integer', desc: 'Default configuration port' }
        scan_rate: { name: 'scan_rate', default_value: 100 , type: 'Float', desc: 'The scanning rate of the component loop in Hz. In each iteration of the loop the component must process its ports and health status. The estimation of the state variables, is defined by the state variable sampling rate and it may use an estimation model. The control of the state variable is defined by the state variable control rate. It must calculate the control output, if necessary with a control model. The scanning rate shall be always higher that the maximum of the sampling or control rate of any of its states variables' }
        acl: { name: 'acl', default_value: 'PRIVATE' , type: 'String', desc: 'Access Control List. List of namespaces that can issue a command to the controller. TBC' }

    state_vars:
        ops_state: { name: 'ops_state', default_value: 'OFF'  }

    input_ports:
        # enable:              { name: 'enable',                protocol: 'pull',  url: 'tcp://127.0.0.1:10104', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # close_loop_hw_ad:    { name: 'close_loop_hw_ad',      protocol: 'pull',  url: 'tcp://127.0.0.1:10103', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # pwm_offset_hw_ad:    { name: 'pwm_offset_hw_ad',      protocol: 'pull',  url: 'tcp://127.0.0.1:10125', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # force_sp_hw_ad:      { name: 'force_sp_hw_ad',        protocol: 'pull',  url: 'tcp://127.0.0.1:10126', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # msthb_hw_ad:         { name: 'msthb_hw_ad',           protocol: 'pull',  url: 'tcp://127.0.0.1:10136', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # date_write_string:   { name: 'date_write_string',     protocol: 'pull',  url: 'tcp://127.0.0.1:20124', blocking_mode: 'async', max_rate: 1000, nom_rate: 100   } #Pierre2
        #date_write:          { name: 'date_write',            protocol: 'pull',  url: 'tcp://127.0.0.1:20125', blocking_mode: 'async', max_rate: 1000, nom_rate: 100   } #Pierre2
        #msthb:               { name: 'msthb',                 protocol: 'pull',  url: 'tcp://127.0.0.1:20126', blocking_mode: 'async', max_rate: 1000, nom_rate: 100   } #Pierre2
        ecat_bus:            { name: 'ecat_bus',              protocol: 'pull',  url: 'tcp://127.0.0.1:10109', blocking_mode: 'async', max_rate: 1000, nom_rate: 100   }
        ops_state_goal:      { name: 'ops_state_goal',        protocol: 'pull',  url: 'tcp://127.0.0.1:10110', blocking_mode: 'async', max_rate: 1000, nom_rate: 100     }
        sdo_read_update_req: { name: 'sdo_read_update_req',   protocol: 'pull',  url: 'tcp://127.0.0.1:10120', blocking_mode: 'async', max_rate: 1000, nom_rate: 100   } #Pierre2
        sdo_write_enable:    { name: 'sdo_write_enable',      protocol: 'pull',  url: 'tcp://127.0.0.1:20122', blocking_mode: 'async', max_rate: 1000, nom_rate: 100   } #Pierre2

        sdo_read_update_req: { name: 'sdo_read_update_req',   protocol: 'pull',  url: 'tcp://127.0.0.1:10120', blocking_mode: 'async', max_rate: 10000, nom_rate: 100   } #Pierre2
        motor_state_goal:    { name: 'motor_state_goal',      protocol: 'pull',  url: 'tcp://127.0.0.1:10165', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika
        motor_velocity_goal: { name: 'motor_velocity_goal',   protocol: 'pull',  url: 'tcp://127.0.0.1:10166', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika
        # motor_state_goal:    { name: 'motor_state_goal',      protocol: 'pull',  url: 'tcp://127.0.0.1:10165', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika
        # motor_velocity_goal: { name: 'motor_velocity_goal',   protocol: 'pull',  url: 'tcp://127.0.0.1:10166', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika


    output_ports:
        # enable_check:        { name: 'enable_check',          protocol: 'push',  url: 'tcp://127.0.0.1:10101', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # close_loop_status:   { name: 'close_loop_status',     protocol: 'push',  url: 'tcp://127.0.0.1:10102', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # err_hw_ad:           { name: 'err_hw_ad',             protocol: 'push',  url: 'tcp://127.0.0.1:10133', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # force_rb:            { name: 'force_rb',              protocol: 'push',  url: 'tcp://127.0.0.1:10132', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # force_sp_status:     { name: 'force_sp_status',       protocol: 'push',  url: 'tcp://127.0.0.1:10127', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # pwm_status:          { name: 'pwm_status',            protocol: 'push',  url: 'tcp://127.0.0.1:10134', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #10134   #Pierre4
        # slvhb_hw_ad:         { name: 'slvhb_hw_ad',           protocol: 'push',  url: 'tcp://127.0.0.1:10135', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }
        # heartbeat_out:       { name: 'heartbeat_out',         protocol: 'push',  url: 'tcp://127.0.0.1:10108', blocking_mode: 'async', max_rate: 1,     nom_rate: 1     }
        ops_state_value:     { name: 'ops_state_value',         protocol: 'push',  url: 'tcp://127.0.0.1:10112', blocking_mode: 'async', max_rate: 1,     nom_rate: 1     }
        sdo_read_update_done: { name: 'sdo_read_update_done',   protocol: 'push',  url: 'tcp://127.0.0.1:10121', blocking_mode: 'async', max_rate: 10000, nom_rate: 100   } #Pierre2

        # motor_state_value:    { name: 'motor_state_value',      protocol: 'push',  url: 'tcp://127.0.0.1:10201', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika
        # motor_velocity_value: { name: 'motor_velocity_value',   protocol: 'push',  url: 'tcp://127.0.0.1:10202', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika
        # motor_position_value: { name: 'motor_position_value',   protocol: 'push',  url: 'tcp://127.0.0.1:10203', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   } #Erika

        # pwm_offset_out:      { name: 'pwm_offset_out',        protocol: 'push',  url: 'tcp://127.0.0.1:10124', blocking_mode: 'async', max_rate: 1000,  nom_rate: 100   }   #Pierre4
