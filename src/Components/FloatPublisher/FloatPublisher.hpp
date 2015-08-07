/*!
 * \file
 * \brief 
 * \author Maciej
 */

#ifndef FLOATPUBLISHER_HPP_
#define FLOATPUBLISHER_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"



namespace Processors {
namespace FloatPublisher {

/*!
 * \class FloatPublisher
 * \brief FloatPublisher processor class.
 *
 * 
 */
class FloatPublisher: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	FloatPublisher(const std::string & name = "FloatPublisher");

	/*!
	 * Destructor
	 */
	virtual ~FloatPublisher();

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

	// Output data streams
	Base::DataStreamOut<float> output;

	// Handlers
	Base::EventHandler2 h_GenerateData;

	// Properties
	Base::Property<float> value;

	
	// Handlers
	void GenerateData();

};

} //: namespace FloatPublisher
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("FloatPublisher", Processors::FloatPublisher::FloatPublisher)

#endif /* FLOATPUBLISHER_HPP_ */
