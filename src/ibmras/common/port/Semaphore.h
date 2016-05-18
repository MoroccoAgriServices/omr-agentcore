/*******************************************************************************
 * Copyright 2016 IBM Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/


#ifndef ibmras_common_port_semaphore_h
#define ibmras_common_port_semaphore_h

#include <vector>
#include <string>
#if defined (_MACH_)
#include <semaphore.h>
#endif

#ifndef NULL
#define NULL 0
#endif

#include "ibmras/common/Logger.h"

namespace ibmras {
namespace common {
namespace port {

/* class to provide semaphore semantics */
class Semaphore {
public:
	Semaphore(uint32 initial, uint32 max);					/* semaphore initial and max count */
	void inc();												/* increase the semaphore count */
	bool wait(uint32 timeout);								/* decrement the semaphore count */
	~Semaphore();											/* OS cleanup of semaphore */
private:

#if defined(_MACH_)
	semaphore_t* handle;
#else
	void* handle;											/* opaque handle to platform data structure */
#endif

};

}
}
}	/*end of namespace port */

#endif /* ibmras_common_port_semaphore_h */
