#ifndef __TELEMETRY_H__
#define __TELEMETRY_H__

#include "basic_include.h"
#include "lwip/ip4_addr.h"

#define TELEMETRY_MQTT_DEFAULT_TOPIC                 ("rnode-halow/telemetry")
#define TELEMETRY_MQTT_DEFAULT_DOMAIN                ("telemetry.rnode-halow.ru")
#define TELEMETRY_MQTT_DEFAULT_USERNAME              ("rnode-halow")
#define TELEMETRY_MQTT_DEFAULT_PASSWORD              ("rnode-halow")

#define TELEMETRY_MQTT_USERNAME_LEN             (32)
#define TELEMETRY_MQTT_PASSWORD_LEN             (32)
#define TELEMETRY_MQTT_TOPIC_LEN                (32)
#define TELEMETRY_NODENAME_LEN                  (32)
#define TELEMETRY_DOMAIN_LEN                    (32)
#define TELEMETRY_FW_VERSION_LEN                (8)

struct telemetry_pkg{
    uint32_t id;
    uint32_t uptime_s;
    uint16_t frequency_x100khz;
    uint8_t bandwidth;
    uint8_t mcs;
    float latitude;
    float longitude;
    bool directional;
    int16_t direction;
    char name[TELEMETRY_NODENAME_LEN];
    char firmware_ver[TELEMETRY_FW_VERSION_LEN];
    uint8_t lxmf[16];
};

struct telemetry_pkg_ext{
    uint64_t tx_bytes;
    uint64_t rx_bytes;
    uint64_t tx_packets;
    uint64_t rx_packets;
};

typedef struct{
    bool enabled;
    bool extended_enabled;
    uint32_t send_period_s;
    char domain[TELEMETRY_DOMAIN_LEN];
    uint16_t port;
    float latitude;
    float longitude;
    bool directional;
    int16_t direction;
    char username[TELEMETRY_MQTT_USERNAME_LEN];
    char password[TELEMETRY_MQTT_PASSWORD_LEN];
    char topic[TELEMETRY_MQTT_TOPIC_LEN];
    char nodename[TELEMETRY_NODENAME_LEN];
    uint8_t lxmf[16];
} telemetry_config_t;

void telemetry_init(void);
void telemetry_config_load( telemetry_config_t *cfg );
void telemetry_config_save( telemetry_config_t *cfg );
void telemetry_send_now( void );

#endif // __TELEMETRY_H__
