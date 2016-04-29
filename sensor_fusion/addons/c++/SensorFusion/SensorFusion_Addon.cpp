#include <node.h>
#include <string>
#include <sstream>
#include <iostream>
#include "SensorFusion.hpp"
#include "Vector3D.hpp"


using namespace std;

namespace demo {
	SensorFusion sensfus;

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Number;
	using v8::Object;
	using v8::String;
	using v8::Value;
	
	void Method(const FunctionCallbackInfo<Value>& args) {
		Vector3D ori;
		ostringstream oss;
		
		sensfus.updateParameters();
		ori = sensfus.getAccAngleEstimate();
		oss << "{\"x\": " << ori.x << "," << "\"y\": " << ori.y << "," << "\"z\": " << ori.z << "}";

		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, oss.str().c_str()));
	}

	void init(Local<Object> exports) {
		  NODE_SET_METHOD(exports, "getOrientation", Method);
	}

	NODE_MODULE(addon, init)
}  // namespace demo
