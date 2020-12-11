#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "social-distancing-e8976.firebaseio.com" //Thay bằng địa chỉ firebase của bạn
#define FIREBASE_AUTH ""   //Không dùng xác thực nên không đổi
#define WIFI_SSID "Hoa Mi"   //Thay wifi và mật khẩu
#define WIFI_PASSWORD "hoami12020"

void setup() {
  Serial.begin(9600);
  pinMode(D12, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void beep(){
    digitalWrite(D12, HIGH);
    delay(50);
    digitalWrite(D12, LOW);
    delay(50);
    digitalWrite(D12, HIGH);
    delay(50);
    digitalWrite(D12, LOW);
    delay(50);
    digitalWrite(D12, HIGH);
    delay(50);
    digitalWrite(D12, LOW);
    delay(50);
}

void loop() {
  String stt = Firebase.getString("/SPEAKER");

  if (stt == "ON")
    beep();
  else
    digitalWrite(D12, LOW);
}
