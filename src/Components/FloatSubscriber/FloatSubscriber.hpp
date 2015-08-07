/*!
 * \file
 * \brief 
 * \author Maciej
 */

#ifndef FLOATSUBSCRIBER_HPP_
#define FLOATSUBSCRIBER_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"



namespace Processors {
namespace FloatSubscriber {

/*!
 * \class FloatSubscriber
 * \brief FloatSubscriber processor class.
 *
 * 
 */
class FloatSubscriber: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	FloatSubscriber(const std::string & name = "FloatSubscriber");

	/*!
	 * Destructor
	 */
	virtual ~FloatSubscriber();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	// Input data streams
	Base::DataStreamIn<float> input;

	// Output data streams

	// Handlers
	Base::EventHandler2 h_onNewData;

	// Properties

	
	// Handlers
	void onNewData();

};

} //: namespace FloatSubscriber
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("FloatSubscriber", Processors::FloatSubscriber::FloatSubscriber)

#endif /* FLOATSUBSCRIBER_HPP_ */
