/*
 * SnapJVMRuntime.hpp
 *
 *  Created on: Nov 7, 2019
 *      Author: grr
 */

#ifndef SNAPJVMRUNTIME_HPP_
#define SNAPJVMRUNTIME_HPP_

#include "Object.hpp"

enum JVMRuntimeCallNumber {
	VirtualCall=1
};

class SnapJVMRuntime;

typedef void * (* InvokeJVMRuntimeFuncPtr)(SnapJVMRuntime * runTime, Object * o, void *a, void *b, void *c, void *d);

enum SnapJVMRuntimeCallTimes{
	JVMRuntime_invokevirtual, // bytecode for _invokevirtual
	JVMRuntime_max
};

class SnapJVMRuntime {
	InvokeJVMRuntimeFuncPtr _runtimeDispatchTable[JVMRuntime_max];

	static bool _verboseMode;

	///////////////////////////////////////////

public:
	static SnapJVMRuntime * _theJVMRuntime;

	static SnapJVMRuntime * TheJVMRuntime();
	SnapJVMRuntime();
	virtual ~SnapJVMRuntime();

	void invokeMethod( Object * o, char * methodName );
	static void setVerboseMode(bool verboseMode);
	static bool isVerboseMode();

	// Calls runtime
	static void * runtime_invokevirtual(SnapJVMRuntime * runTime, Object * o, void *a, void *b, void *c, void *d);
};

inline SnapJVMRuntime *
SnapJVMRuntime::TheJVMRuntime()
{
	return _theJVMRuntime;
}

inline void
SnapJVMRuntime::setVerboseMode(bool verboseMode) {
	_verboseMode = verboseMode;
}

inline bool
SnapJVMRuntime::isVerboseMode()
{
	return _verboseMode;
}

#endif /* SNAPJVMRUNTIME_HPP_ */

