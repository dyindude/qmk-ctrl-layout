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
  stage('symlink our keymaps') {
    sh 'find keymaps ! -path keymaps -type d -exec echo ln -s {} qmk-firmware/keyboards/massdrop/ctrl/keymaps/. \\;'
  }
  stage('ls keymaps folder') {
    sh 'ls -Alh qmk-firmware/keyboards/massdrop/ctrl/keymaps'
  }
}
