// hello.cc
#include <node.h>
#include "fm19Console\GameVersions.h"
#include "fm19Console\Helpers.h"
#include "fm19Console\service\ServiceMyProfile.h"

using namespace v8;
using namespace std;

//Current team setting
unsigned int currentMoney;

//Change team setting
int newMoney;


void myProfile(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
	HANDLE phandle = GameLoad(windowName);
    ServiceMyProfile serviceMyProfile;

	//--------------Reputation------------------
	short getHomeRep      = serviceMyProfile.reputation.getHomeRep(phandle);
	short getCurrentRep   = serviceMyProfile.reputation.getCurrentRep(phandle);
	short getWorldRep     = serviceMyProfile.reputation.getWorldRep(phandle);


	//--------------Characteristic--------------
	short getHandsOnApproach     = serviceMyProfile.characteristic.getHandsOnApproach(phandle);
	short getTacticalConsistency = serviceMyProfile.characteristic.getTacticalConsistency(phandle);
	short getClubPlayerLoyalty   = serviceMyProfile.characteristic.getClubPlayerLoyalty(phandle);
	short getSquadDiscipline     = serviceMyProfile.characteristic.getSquadDiscipline(phandle);
	short getFinancialControl    = serviceMyProfile.characteristic.getFinancialControl(phandle);
	int   getMediaHandling       = serviceMyProfile.characteristic.getMediaHandling(phandle);

   Local<Object> obj = Object::New(isolate);
   Local<Object> reputation = Object::New(isolate);
   reputation->Set(String::NewFromUtf8(isolate, "getHomeRep"),  Integer::New(isolate, getHomeRep));
   reputation->Set(String::NewFromUtf8(isolate, "getCurrentRep"),  Integer::New(isolate, getCurrentRep));
   reputation->Set(String::NewFromUtf8(isolate, "getWorldRep"),  Integer::New(isolate, getWorldRep));

   obj->Set(String::NewFromUtf8(isolate, "reputation"), reputation);
   Local<Object> characteristic = Object::New(isolate);

   characteristic->Set(String::NewFromUtf8(isolate, "getHandsOnApproach"),  Integer::New(isolate, getHandsOnApproach));
   characteristic->Set(String::NewFromUtf8(isolate, "getTacticalConsistency"),  Integer::New(isolate, getTacticalConsistency));
   characteristic->Set(String::NewFromUtf8(isolate, "getClubPlayerLoyalty"),  Integer::New(isolate, getClubPlayerLoyalty));
   characteristic->Set(String::NewFromUtf8(isolate, "getSquadDiscipline"),  Integer::New(isolate, getSquadDiscipline));
   characteristic->Set(String::NewFromUtf8(isolate, "getFinancialControl"),  Integer::New(isolate, getFinancialControl));
   characteristic->Set(String::NewFromUtf8(isolate, "getMediaHandling"),  Integer::New(isolate, getMediaHandling));
   // below here i am trying to include the object "obj_lvl" into the first object "obj"

   obj->Set(String::NewFromUtf8(isolate, "characteristic"), characteristic);

       args.GetReturnValue().Set(obj);

}


void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "myProfile", myProfile);
}

NODE_MODULE(fm19js, init)


