/*!
 * \file
 * \brief 
 * \author Maciej Stefańczyk
 */

#ifndef INFERENCE_HPP_
#define INFERENCE_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"



namespace Processors {
namespace Inference {

/*!
 * \class Inference
 * \brief Inference processor class.
 *
 * Fuzzy inference engine
 */
class Inference: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	Inference(const std::string & name = "Inference");

	/*!
	 * Destructor
	 */
	virtual ~Inference();

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
	Base::DataStreamIn<std::vector<float> > input;

	// Output data streams
	Base::DataStreamOut<std::vector<float> > output;

	// Handlers
	Base::EventHandler2 h_onNewData;

	// Properties

	
	// Handlers
	void onNewData();

};

} //: namespace Inference
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("Inference", Processors::Inference::Inference)

#endif /* INFERENCE_HPP_ */
