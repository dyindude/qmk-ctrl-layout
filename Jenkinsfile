node {
  dir('qmk-firmware') {
    git url: 'https://github.com/qmk/qmk_firmware.git'
  }

  stage('Build qmk_firmware image') {
    docker.build("local/qmk_firmware", "-f qmk_firmware/Dockerfile .")
  }
}
