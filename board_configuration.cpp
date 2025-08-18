#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::D15;
}

Gpio getRunningLedPin() {
	return Gpio::D12;
}

Gpio getWarningLedPin() {
	return Gpio::D13;
}

// board-specific configuration setup
static void customBoardDefaultConfiguration() {
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;
	
    engineConfiguration->injectionPins[0] = Gpio::E6;
	engineConfiguration->injectionPins[1] = Gpio::E5;
	engineConfiguration->injectionPins[2] = Gpio::B9;
	engineConfiguration->injectionPins[3] = Gpio::E3;
	engineConfiguration->injectionPins[4] = Gpio::D9;
	engineConfiguration->injectionPins[5] = Gpio::B14;
	engineConfiguration->injectionPins[6] = Gpio::C13;
	engineConfiguration->injectionPins[7] = Gpio::E14;
	
    engineConfiguration->ignitionPins[0] = Gpio::B13;
	engineConfiguration->ignitionPins[1] = Gpio::E9;
	engineConfiguration->ignitionPins[2] = Gpio::A8;
	engineConfiguration->ignitionPins[3] = Gpio::E4;
	engineConfiguration->ignitionPins[4] = Gpio::D3;
	engineConfiguration->ignitionPins[5] = Gpio::D11;
	engineConfiguration->ignitionPins[6] = Gpio::D10;
	engineConfiguration->ignitionPins[7] = Gpio::D8;

	engineConfiguration->fanPin = Gpio::E7;
	engineConfiguration->fuelPumpPin = Gpio::E8;
	engineConfiguration->tachOutputPin = Gpio::E10;
	engineConfiguration->vehicleSpeedSensorInputPin = Gpio::C7;

	engineConfiguration->map.sensor.hwChannel = EFI_ADC_8;
	engineConfiguration->clt.adcChannel = EFI_ADC_14;
	engineConfiguration->iat.adcChannel = EFI_ADC_1;
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_15;
	engineConfiguration->afr.hwChannel = EFI_ADC_2;
	engineConfiguration->baroSensor.hwChannel = EFI_ADC_11;

	/* Battery voltage */
	engineConfiguration->vbattAdcChannel = EFI_ADC_9;
	/* Vbat divider: 10K + 1K */
	engineConfiguration->vbattDividerCoeff = 8.23;

	engineConfiguration->triggerInputPins[0] = Gpio::C6;
	engineConfiguration->camInputs[0] = Gpio::A5;

    engineConfiguration->analogInputDividerCoefficient = 1.56f;
	engineConfiguration->adcVcc = 3.3f;

	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;


}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
