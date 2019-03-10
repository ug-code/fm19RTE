{
  "targets": [
    {
      "target_name": "fm19js",
      "sources": [ "app/lib/fm19js.cc",
      "cpp/fm19Console/GameVersions.h",
      "cpp/fm19Console/Helpers.h",
      "cpp/fm19Console/service/ServiceMyProfile.h",
      "cpp/fm19Console/service/ServiceCurrentClub.h"
      ],
        "include_dirs": [
          "cpp"
      ],
      'direct_dependent_settings': {
        'include_dirs': [ 'cpp/' ],
      }

    }
  ]
}