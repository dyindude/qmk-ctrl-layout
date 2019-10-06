node('master') {
  def qmk
  checkout scm
  stage('Clone qmk_firmware') {
    dir('qmk-firmware') {
      git url: 'https://github.com/qmk/qmk_firmware.git'
    }
  }
  stage('copy keymaps') {
    sh 'find ${WORKSPACE}/keymaps ! -path ${WORKSPACE}/keymaps -type d -exec cp -rv {} qmk-firmware/keyboards/massdrop/ctrl/keymaps/. \\;'
  }
  stage('Build qmk_firmware image') {
    docker.build("local/qmk_firmware", "-f qmk-firmware/Dockerfile qmk-firmware")
  }
  stage('Build qmk_keymaps image (builds keymaps)') {
    qmk = docker.build("local/qmk_firmware:local_keymaps")
  }
  stage('copy .bin files') {
    qmk.inside {
      sh 'mkdir -p /data/build/${JOB_NAME} && rm /data/build/${JOB_NAME}/* && cp /*.bin /data/build/${JOB_NAME}/. -v'
    }
  }
}
