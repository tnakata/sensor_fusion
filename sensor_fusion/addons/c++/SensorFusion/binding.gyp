{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ 
        "SensorFusion_Addon.cpp", "SensorFusion.cpp", "Vector3D.cpp"
      ],
      "include_dirs": [
        "/usr/include/upm/","/usr/include/mraa/"
      ],
      "libraries": [
        "/usr/lib/libupm-lsm9ds0.so"
      ],
      "cflags": [ "-fexceptions" ],
      "cflags_cc": [ "-fexceptions" ]
    }
  ]
}
