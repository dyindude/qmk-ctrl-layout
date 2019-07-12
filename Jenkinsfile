node {
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
    def qmk = docker.build("local/qmk_firmware", "-f qmk-firmware/Dockerfile .")
  }
  stage('Run build?') {
    qmk.inside("-v ${WORKSPACE}/keymaps/testlayout:/qmk-firmware/keyboards/massdrop/ctrl/keymaps/testlayout") {
      sh 'ls -Alh qmk-firmware/keyboards/massdrop/ctrl/keymaps'
    }
  }
}
