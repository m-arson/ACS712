float nilai_tengah = 512.0;

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
}
void loop() {
  int max = 0;
  int min = 9999;
  for(int i = 0; i < 250; ++i) {
    int c = analogRead(A1);
    if(c > max) {
      max = c;
    }
    if(c < min) {
      min = c;
    }
  }
  int atas = max - 512;
  int bawah = min - 512;
  float nilai_asli = atas - bawah;
  //nilai_asli = (nilai_asli < 5) ? 0 : nilai_asli;
  float nilai_adc = 512 - nilai_asli;
  float curr = (2.5 - (nilai_adc * 0.00488))/0.185;
  curr = curr - 0.17;
  if(curr < 0.05) {
    curr = 0;
  }
  Serial.println("Nilai Arus : " + String(curr) + "  --> " + String(nilai_asli));
  delay(100);
}
