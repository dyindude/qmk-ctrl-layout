node('master') {
  checkout scm
  stage('Clone qmk_firmware') {
    dir('qmk-firmware') {
      git url: 'https://github.com/qmk/qmk_firmware.git'
    }
  }
//  stage('symlink our keymaps') {
//    sh 'find ${WORKSPACE}/keymaps ! -path ${WORKSPACE}/keymaps -type d -exec ln -s {} qmk-firmware/keyboards/massdrop/ctrl/keymaps/. \\;'
//  }
//  stage('ls keymaps folder') {
//    sh 'ls -Alh qmk-firmware/keyboards/massdrop/ctrl/keymaps'
//  }
  stage('Build qmk_firmware image') {
    docker.build("local/qmk_firmware", "-f qmk-firmware/Dockerfile qmk-firmware")
  }
  stage('Build qmk_keymaps image (builds keymaps)') {
    docker.build("local/qmk_keymaps")
  }
}
