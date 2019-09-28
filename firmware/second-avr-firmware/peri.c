#include <avr/io.h>
#include "peri.h"

void init_peripheral()
{
	//DDRC = 0b00000111;
	DDRC = DDRC | (1<<PC0);
	DDRC = DDRC | (1<<PC1);
	DDRC = DDRC | (1<<PC2);
	DDRC &= ~(1<<PC3);
	DDRC &= ~(1<<PC4);

	PORTC &= ~(1<<PC0);
	PORTC &= ~(1<<PC1);
	PORTC &= ~(1<<PC2);
	PORTC = PORTC| (1<<PC3);
	PORTC &= ~(1<<PC4);
}

void set_led(uint8_t pin, uint8_t state)
{

	if (state) {
	PORTC |= (1<<pin);
	} else {
	PORTC &= ~(1<<pin);
	}

}

void set_led_value(uint8_t x)
{
PORTC &= ~(0b00000111); // Clear bits PC2-PC0
PORTC |= (x & 0b00000111);
}

uint16_t read_adc(uint8_t channel)
{
ADMUX = (0<<REFS1)|(1<<REFS0) // ระบุให้ใช้ VCC เป็ นแรงดันอ้างอิง (Vref) และ
		| (0<<ADLAR) // บันทึกผลลัพธ์ชิดขวาในคู่รีจีสเตอร์ADCH/ADCL
		| (channel & 0b1111); // ตั้งค่า MUX เป็ นค่า channel
	ADCSRA = (1<<ADEN) // เปิ ดวงจร ADC
		| (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0) // ใช้ความเร็ว 1/128 ของคล็อกระบบ
		| (1<<ADSC); // สั่งวงจร ADC ให้เริ่มต้นการแปลง
	while ((ADCSRA & (1<<ADSC))) // รอจนบิต ADSC กลายเป็ น 0 ซึ่งหมายถึงการแปลงเสร็จสิ้ น
	;
	return ADCL + ADCH*256; // ผลลัพธ์ถูกเก็บอยู่ในรีจีสเตอร์ADCL และ ADCH
	// สามารถใช้ return ADC ได้เช่นกัน
}

uint16_t get_light()
{
    return read_adc(PC4);
}
