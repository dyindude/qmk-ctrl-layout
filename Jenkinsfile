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
    qmk = docker.build("local/qmk_firmware", "-f qmk-firmware/Dockerfile qmk-firmware")
  }
  stage('Build/deliver layouts') {
    qmk.inside {
      sh 'cd qmk-firmware && git checkout e83e3165559eba17a965541726b5c09112bab9d5 && make massdrop/ctrl:testlayout'
      sh 'cd qmk-firmware && git checkout master && make massdrop/ctrl:dyindude_md
      sh 'mkdir -p /data/build/${JOB_NAME} && rm -f /data/build/${JOB_NAME}/* && cp qmk-firmware/*.bin /data/build/${JOB_NAME}/. -v'
    }
  }
}
