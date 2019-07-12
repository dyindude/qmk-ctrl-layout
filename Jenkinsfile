node {
  dir('qmk-firmware') {
    git url: 'git@github.com:qmk/qmk_firmware.git'
    //git url: 'https://github.com/qmk/qmk_firmware.git'
  }

  stage('Build qmk_firmware image') {
    docker.build("local/qmk_firmware", "-f qmk_firmware/Dockerfile")
  }
}
