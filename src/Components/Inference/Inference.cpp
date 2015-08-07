/*!
 * \file
 * \brief
 * \author Maciej Stefańczyk
 */

#include <memory>
#include <string>

#include "Inference.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace Inference {

Inference::Inference(const std::string & name) :
		Base::Component(name)  {

}

Inference::~Inference() {
}

void Inference::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	registerStream("input", &input);
	registerStream("output", &output);
	// Register handlers
	h_onNewData.setup(boost::bind(&Inference::onNewData, this));
	registerHandler("onNewData", &h_onNewData);
	addDependency("onNewData", &input);

}

bool Inference::onInit() {

	return true;
}

bool Inference::onFinish() {
	return true;
}

bool Inference::onStop() {
	return true;
}

bool Inference::onStart() {
	return true;
}

void Inference::onNewData() {
}



} //: namespace Inference
} //: namespace Processors
