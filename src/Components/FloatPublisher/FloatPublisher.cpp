/*!
 * \file
 * \brief
 * \author Maciej
 */

#include <memory>
#include <string>

#include "FloatPublisher.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace FloatPublisher {

FloatPublisher::FloatPublisher(const std::string & name) :
		Base::Component(name) , 
		value("value", 0.5) {
	registerProperty(value);

}

FloatPublisher::~FloatPublisher() {
}

void FloatPublisher::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	registerStream("output", &output);
	// Register handlers
	h_GenerateData.setup(boost::bind(&FloatPublisher::GenerateData, this));
	registerHandler("GenerateData", &h_GenerateData);
	addDependency("GenerateData", NULL);
}

bool FloatPublisher::onInit() {

	return true;
}

bool FloatPublisher::onFinish() {
	return true;
}

bool FloatPublisher::onStop() {
	return true;
}

bool FloatPublisher::onStart() {
	return true;
}

void FloatPublisher::GenerateData() {
	output.write(value);
}



} //: namespace FloatPublisher
} //: namespace Processors
