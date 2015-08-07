/*!
 * \file
 * \brief
 * \author Maciej
 */

#include <memory>
#include <string>

#include "FloatSubscriber.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace FloatSubscriber {

FloatSubscriber::FloatSubscriber(const std::string & name) :
		Base::Component(name)  {

}

FloatSubscriber::~FloatSubscriber() {
}

void FloatSubscriber::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	registerStream("input", &input);
	// Register handlers
	h_onNewData.setup(boost::bind(&FloatSubscriber::onNewData, this));
	registerHandler("onNewData", &h_onNewData);
	addDependency("onNewData", &input);

}

bool FloatSubscriber::onInit() {

	return true;
}

bool FloatSubscriber::onFinish() {
	return true;
}

bool FloatSubscriber::onStop() {
	return true;
}

bool FloatSubscriber::onStart() {
	return true;
}

void FloatSubscriber::onNewData() {
	CLOG(LINFO) << input.read();
}



} //: namespace FloatSubscriber
} //: namespace Processors
