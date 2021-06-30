#include "plugin.hpp"
#include <iostream>


struct N8NYERouter : Module {
	enum ParamIds {
		SWITCH_1,
		SWITCH_2,
		SWITCH_3,
		SWITCH_4,
		SWITCH_5,
		NUM_PARAMS
	};
	enum InputIds {
		INPUT_1,
		INPUT_2,
		INPUT_3,
		INPUT_4,
		INPUT_5,
		NUM_INPUTS
	};
	enum OutputIds {
		OUTPUT_1,
		OUTPUT_2,
		OUTPUT_3,
		OUTPUT_4,
		OUTPUT_5,
		MAIN_OUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		LIGHT_1,
		LIGHT_2,
		LIGHT_3,
		LIGHT_4,
		LIGHT_5,
		NUM_LIGHTS
	};

	N8NYERouter() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
	}

	void process(const ProcessArgs& args) override {


		float in_voltage_1 = inputs[INPUT_1].getVoltage(); 
		float in_voltage_2 = inputs[INPUT_2].getVoltage();
		float in_voltage_3 = inputs[INPUT_3].getVoltage();
		float in_voltage_4 = inputs[INPUT_4].getVoltage();
		float in_voltage_5 = inputs[INPUT_5].getVoltage();

		float switch_1 = params[SWITCH_1].getValue();
		float switch_2 = params[SWITCH_2].getValue();
		float switch_3 = params[SWITCH_3].getValue();
		float switch_4 = params[SWITCH_4].getValue();
		float switch_5 = params[SWITCH_5].getValue();

		lights[LIGHT_1].value = params[SWITCH_1].getValue();
		lights[LIGHT_2].value = params[SWITCH_2].getValue();
		lights[LIGHT_3].value = params[SWITCH_3].getValue();
		lights[LIGHT_4].value = params[SWITCH_4].getValue();
		lights[LIGHT_5].value = params[SWITCH_5].getValue();

		 
		float out_voltage_1 = (switch_1 != 0) ? in_voltage_1 : 0;
		float out_voltage_2 = (switch_2 != 0) ? in_voltage_2 : 0;
		float out_voltage_3 = (switch_3 != 0) ? in_voltage_3 : 0;
		float out_voltage_4 = (switch_4 != 0) ? in_voltage_4 : 0;
		float out_voltage_5 = (switch_5 != 0) ? in_voltage_5 : 0;


		outputs[OUTPUT_1].setVoltage(out_voltage_1);
		outputs[OUTPUT_2].setVoltage(out_voltage_2);
		outputs[OUTPUT_3].setVoltage(out_voltage_3);
		outputs[OUTPUT_4].setVoltage(out_voltage_4);
		outputs[OUTPUT_5].setVoltage(out_voltage_5);


		float totalVoltage = out_voltage_1 + out_voltage_2 +out_voltage_3 + out_voltage_4 + out_voltage_5;
		outputs[MAIN_OUT].setVoltage(totalVoltage);

	}
};
struct N8NYENKK : app::SvgSwitch {
	N8NYENKK() {
		/*
		addFrame(APP->window->loadSvg(asset::system("res/ComponentLibrary/NKK_0.svg")));
		addFrame(APP->window->loadSvg(asset::system("res/ComponentLibrary/NKK_2.svg")));
		*/

		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/N8NYENKK_0.svg")));
		addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/N8NYENKK_2.svg")));
	}
};

struct N8NYERouterWidget : ModuleWidget {
	N8NYERouterWidget(N8NYERouter* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/N8NYERouter.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH,RACK_GRID_HEIGHT * 0.2), module, N8NYERouter::INPUT_1));
		addParam(createParam<N8NYENKK>(Vec(RACK_GRID_WIDTH * 3,RACK_GRID_HEIGHT * 0.2 - 10), module, N8NYERouter::SWITCH_1 ));
		addChild(createLight<LargeLight<WhiteLight>>(Vec(RACK_GRID_WIDTH * 5.5,RACK_GRID_HEIGHT * 0.2 + 5), module, N8NYERouter::LIGHT_1));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH * 7,RACK_GRID_HEIGHT * 0.2), module, N8NYERouter::OUTPUT_1));

		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH,RACK_GRID_HEIGHT * 0.3), module, N8NYERouter::INPUT_2));
		addParam(createParam<N8NYENKK>(Vec(RACK_GRID_WIDTH * 3,RACK_GRID_HEIGHT * 0.3 - 10), module, N8NYERouter::SWITCH_2 ));
		addChild(createLight<LargeLight<WhiteLight>>(Vec(RACK_GRID_WIDTH * 5.5,RACK_GRID_HEIGHT * 0.3 + 5), module, N8NYERouter::LIGHT_2));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH * 7,RACK_GRID_HEIGHT * 0.3), module, N8NYERouter::OUTPUT_2));

		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH,RACK_GRID_HEIGHT * 0.4), module, N8NYERouter::INPUT_3));
		addParam(createParam<N8NYENKK>(Vec(RACK_GRID_WIDTH * 3,RACK_GRID_HEIGHT * 0.4 - 10), module, N8NYERouter::SWITCH_3 ));
		addChild(createLight<LargeLight<WhiteLight>>(Vec(RACK_GRID_WIDTH * 5.5,RACK_GRID_HEIGHT * 0.4 + 5), module, N8NYERouter::LIGHT_3));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH * 7,RACK_GRID_HEIGHT * 0.4), module, N8NYERouter::OUTPUT_3));

		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH,RACK_GRID_HEIGHT * 0.5), module, N8NYERouter::INPUT_4));
		addParam(createParam<N8NYENKK>(Vec(RACK_GRID_WIDTH * 3,RACK_GRID_HEIGHT * 0.5 - 10), module, N8NYERouter::SWITCH_4 ));
		addChild(createLight<LargeLight<WhiteLight>>(Vec(RACK_GRID_WIDTH * 5.5,RACK_GRID_HEIGHT * 0.5 + 5), module, N8NYERouter::LIGHT_4));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH * 7,RACK_GRID_HEIGHT * 0.5), module, N8NYERouter::OUTPUT_4));

		addInput(createInput<PJ301MPort>(Vec(RACK_GRID_WIDTH,RACK_GRID_HEIGHT * 0.6), module, N8NYERouter::INPUT_5));
		addParam(createParam<N8NYENKK>(Vec(RACK_GRID_WIDTH * 3,RACK_GRID_HEIGHT * 0.6 - 10), module, N8NYERouter::SWITCH_5 ));
		addChild(createLight<LargeLight<WhiteLight>>(Vec(RACK_GRID_WIDTH * 5.5,RACK_GRID_HEIGHT * 0.6 + 5), module, N8NYERouter::LIGHT_5));
		addOutput(createOutput<PJ301MPort>(Vec(RACK_GRID_WIDTH * 7,RACK_GRID_HEIGHT * 0.6), module, N8NYERouter::OUTPUT_5));

		addOutput(createOutput<PJ3410Port>(Vec(RACK_GRID_WIDTH * 6,RACK_GRID_HEIGHT * 0.7), module, N8NYERouter::MAIN_OUT));
		
	}
};


Model* modelN8NYERouter = createModel<N8NYERouter, N8NYERouterWidget>("N8NYERouter");