#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <Preferences.h>
#include "global.h"
#include "voipphone.h"

struct WifiSettings {    
    String ssid = "";
    String password = "";
    String hostname = "fingerprintVoipDoorbell";
};

struct AppSettings {
    String mqttServer = "";
    String mqttUsername = "";
    String mqttPassword = "";
    String mqttRootTopic = "fingerprintVoipDoorbell";
    uint8_t ringtime = 1;
    String ntpServer = "pool.ntp.org";
    String sensorPin = "00000000";
    String sensorPairingCode = "";
    int8_t touchRingActiveColor = 2;
    int8_t touchRingActiveSequence = 1;
    int8_t scanColor = 1;
    int8_t matchColor = 3;
    int8_t enrollTemplates = 5;
    bool   sensorPairingValid = false;
    String sip_ip = "";
    String sip_user = "";
    String sip_pass = "";
    uint8_t sipTimeoutDial = 15;
    uint16_t sipTimeoutConnect = 60;
    uint8_t amp_gain = AMP_GAIN;
    uint8_t mic_gain = MIC_GAIN;
    bool   echocompensation = false;
    long   echothreshold = 100;
    uint8_t echodamping = 1;
    String calldevicename = "";
    String phonenumber = "";
    String phonenumber2 = "";
};

class SettingsManager {       
  private:
    WifiSettings wifiSettings;
    AppSettings appSettings;

    void saveWifiSettings();
    void saveAppSettings();

  public:
    bool loadWifiSettings();
    bool loadAppSettings();

    WifiSettings getWifiSettings();
    void saveWifiSettings(WifiSettings newSettings);
    
    AppSettings getAppSettings();
    void saveAppSettings(AppSettings newSettings);

    bool isWifiConfigured();

    bool deleteAppSettings();
    bool deleteWifiSettings();

    String generateNewPairingCode();

};

#endif
