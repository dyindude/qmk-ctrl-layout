node {
  checkout scm
  stage('Clone qmk_firmware') {
    dir('qmk-firmware') {
      git url: 'https://github.com/qmk/qmk_firmware.git'
    }
  }
  stage('Build qmk_firmware image') {
    docker.build("local/qmk_firmware", "-f qmk-firmware/Dockerfile .")
  }
  stage('symlink our layouts') {
    sh 'find layouts -type d -exec ln -s {} qmk-firmware/keyboards/massdrop/ctrl/layouts/. \\;'
  }
  stage('ls layouts folder') {
    sh 'ls -Alh qmk-firmware/keyboards/massdrop/ctrl/layouts'
  }
}
