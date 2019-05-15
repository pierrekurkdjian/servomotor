#!/usr/bin/coffee

msgpack = require 'msgpack-lite'
nn=require 'nanomsg'


host = '127.0.0.1'

send_config = (name, conf, url) ->

    #encode
    packed_conf = msgpack.encode (conf)

    #and send it to the port
    s = new nn.Socket ('push')
    s.connect url
    s.send packed_conf
    console.log 'Done!'

send_component_config = (name, conf_file, url) ->
    console.log 'Sending configuration for '+name+'...'
    conf =  require conf_file

    send_config name, conf, url

send_ethercat_config = (name, conf_file, url) ->
    console.log 'Sending ethercat configuration for '+name+'...'
    conf =  require conf_file

    send_config name, conf.ethercat_config, url

servo_configurables = [
    # {
    #     name: 'emf_weather_ctrl'
    #     url: 'tcp://'+host+':21000'
    #     conf_file: './conf/emf_ctrl_pkg/emf_weather_ctrl/emf_weather_ctrl_config.coffee'
    # }
    # {
    #    name: 'emf_vaisala1_hw_adapter'
    #    url: 'tcp://'+host+':22000'
    #    conf_file: './conf/emf_ctrl_pkg/emf_vaisala_hw_adapter/emf_vaisala1_hw_adapter_config.coffee'
    # }
    # {
    #    name: 'emf_vaisala2_hw_adapter'
    #    url: 'tcp://'+host+':23000'
    #    conf_file: './conf/emf_ctrl_pkg/emf_vaisala_hw_adapter/emf_vaisala2_hw_adapter_config.coffee'
    # }
    # {
    #     name: 'emf_vaisala1_hw_adapter_sim'
    #     url: 'tcp://'+host+':22000'
    #     conf_file: './conf/emf_ctrl_pkg/emf_vaisala_hw_adapter_sim/emf_vaisala1_hw_adapter_sim_config.coffee'
    # }
    # {
    #     name: 'servo_sa_hw_adapter_sim'
    #     url: 'tcp://'+host+':10011'
    #     conf_file: './conf/servo_ctrl_pkg/servo_sa_hw_adapter_sim/servo_sa_hw1_adapter_sim_config.coffee'
    # }
    {
        name: 'servo_sa_hw_adapter'
        url: 'tcp://'+host+':10011'
        conf_file: './conf/servo_ctrl_pkg/servo_sa_hw_adapter/servo_sa_hw1_adapter_config.coffee'
    }
    # {
    #     name: 'servo_sa_main_ctrl'
    #     url: 'tcp://'+host+':10010'
    #     conf_file: './conf/servo_ctrl_pkg/servo_sa_main_ctrl/servo_sa_main_ctrl_config.coffee'
    # }

]

send_component_config component.name, component.conf_file, component.url for component in servo_configurables
send_ethercat_config 'HW Adapter Ethercat Bus', './conf/servo_ctrl_pkg/servo_sa_hw_adapter/ethercat_config.coffee', 'tcp://127.0.0.1:10109'
