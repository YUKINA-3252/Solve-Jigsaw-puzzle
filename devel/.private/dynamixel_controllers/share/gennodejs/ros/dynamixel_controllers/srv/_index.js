
"use strict";

let SetComplianceMargin = require('./SetComplianceMargin.js')
let SetSpeed = require('./SetSpeed.js')
let SetCompliancePunch = require('./SetCompliancePunch.js')
let TorqueEnable = require('./TorqueEnable.js')
let StopController = require('./StopController.js')
let StartController = require('./StartController.js')
let SetComplianceSlope = require('./SetComplianceSlope.js')
let SetTorqueLimit = require('./SetTorqueLimit.js')
let RestartController = require('./RestartController.js')

module.exports = {
  SetComplianceMargin: SetComplianceMargin,
  SetSpeed: SetSpeed,
  SetCompliancePunch: SetCompliancePunch,
  TorqueEnable: TorqueEnable,
  StopController: StopController,
  StartController: StartController,
  SetComplianceSlope: SetComplianceSlope,
  SetTorqueLimit: SetTorqueLimit,
  RestartController: RestartController,
};
