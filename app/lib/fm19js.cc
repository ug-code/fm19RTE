// hello.cc
#include <node.h>
#include "fm19Console\GameVersions.h"
#include "fm19Console\Helpers.h"
#include "fm19Console\service\ServiceMyProfile.h"
#include "fm19Console\service\ServiceCurrentClub.h"

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

void currentClub(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HANDLE phandle = GameLoad(windowName);
    ServiceCurrentClub serviceCurrentClub;

    //--------------Reputation------------------
    int getRowId                 = serviceCurrentClub.getRowId(phandle);
    int getUniqeId               = serviceCurrentClub.getUniqeId(phandle);
    char* getFullname            = serviceCurrentClub.getFullname(phandle);
    char* getNickname            = serviceCurrentClub.getNickname(phandle);
    short getTeamType            = serviceCurrentClub.getTeamType(phandle);
    short getReputation          = serviceCurrentClub.getReputation(phandle);
    char* getNation              = serviceCurrentClub.getNation(phandle);
    short getOwnershipType       = serviceCurrentClub.getOwnershipType(phandle);
    short getChairmanTitle       = serviceCurrentClub.getChairmanTitle(phandle);
    short getChairmanStatus      = serviceCurrentClub.getChairmanStatus(phandle);
    short getTrainingFacilities  = serviceCurrentClub.getTrainingFacilities(phandle);
    short getYouthFacilities     = serviceCurrentClub.getYouthFacilities(phandle);
    short getYouthImportance     = serviceCurrentClub.getYouthImportance(phandle);
    short getYouthRecruitment    = serviceCurrentClub.getYouthRecruitment(phandle);
    short getJuniorCoaching      = serviceCurrentClub.getJuniorCoaching(phandle);
    short getCorporateFacilities = serviceCurrentClub.getCorporateFacilities(phandle);
    short getMorale              = serviceCurrentClub.getMorale(phandle);
    short getAverageAttendance   = serviceCurrentClub.getAverageAttendance(phandle);
    short getMinimumAttendance   = serviceCurrentClub.getMinimumAttendance(phandle);


      /*
    //--------------Finances--------------
    short getHandsOnApproach     = serviceMyProfile.characteristic.getHandsOnApproach(phandle);
    short getTacticalConsistency = serviceMyProfile.characteristic.getTacticalConsistency(phandle);
    short getClubPlayerLoyalty   = serviceMyProfile.characteristic.getClubPlayerLoyalty(phandle);
    short getSquadDiscipline     = serviceMyProfile.characteristic.getSquadDiscipline(phandle);
    short getFinancialControl    = serviceMyProfile.characteristic.getFinancialControl(phandle);
    int   getMediaHandling       = serviceMyProfile.characteristic.getMediaHandling(phandle);
    */

    Local<Object> obj = Object::New(isolate);

    Local<Object> information = Object::New(isolate);
    information->Set(String::NewFromUtf8(isolate, "getRowId"),  Integer::New(isolate, getRowId));
    information->Set(String::NewFromUtf8(isolate, "getUniqeId"),  Integer::New(isolate, getUniqeId));
    information->Set(String::NewFromUtf8(isolate, "getFullname"),  String::NewFromUtf8(isolate, getFullname));
    information->Set(String::NewFromUtf8(isolate, "getNickname"),  String::NewFromUtf8(isolate, getNickname));
    information->Set(String::NewFromUtf8(isolate, "getTeamType"),  Integer::New(isolate, getTeamType));
    information->Set(String::NewFromUtf8(isolate, "getReputation"),  Integer::New(isolate, getReputation));
    information->Set(String::NewFromUtf8(isolate, "getNation"),  String::NewFromUtf8(isolate, getNation));
    information->Set(String::NewFromUtf8(isolate, "getOwnershipType"),  Integer::New(isolate, getOwnershipType));
    information->Set(String::NewFromUtf8(isolate, "getChairmanTitle"),  Integer::New(isolate, getChairmanTitle));
    information->Set(String::NewFromUtf8(isolate, "getChairmanStatus"),  Integer::New(isolate, getChairmanStatus));
    information->Set(String::NewFromUtf8(isolate, "getTrainingFacilities"),  Integer::New(isolate,
    getTrainingFacilities));
    information->Set(String::NewFromUtf8(isolate, "getYouthFacilities"),  Integer::New(isolate, getYouthFacilities));
    information->Set(String::NewFromUtf8(isolate, "getYouthImportance"),  Integer::New(isolate, getYouthImportance));
    information->Set(String::NewFromUtf8(isolate, "getYouthRecruitment"),  Integer::New(isolate, getYouthRecruitment));
    information->Set(String::NewFromUtf8(isolate, "getJuniorCoaching"),  Integer::New(isolate, getJuniorCoaching));
    information->Set(String::NewFromUtf8(isolate, "getCorporateFacilities"),  Integer::New(isolate,getCorporateFacilities));
    information->Set(String::NewFromUtf8(isolate, "getMorale"),  Integer::New(isolate, getMorale));
    information->Set(String::NewFromUtf8(isolate, "getAverageAttendance"),  Integer::New(isolate, getAverageAttendance));
    information->Set(String::NewFromUtf8(isolate, "getMinimumAttendance"),  Integer::New(isolate, getMinimumAttendance));


    obj->Set(String::NewFromUtf8(isolate, "information"), information);

    /*
    Local<Object> characteristic = Object::New(isolate);

    characteristic->Set(String::NewFromUtf8(isolate, "getHandsOnApproach"),  Integer::New(isolate, getHandsOnApproach));
    characteristic->Set(String::NewFromUtf8(isolate, "getTacticalConsistency"),  Integer::New(isolate, getTacticalConsistency));
    characteristic->Set(String::NewFromUtf8(isolate, "getClubPlayerLoyalty"),  Integer::New(isolate, getClubPlayerLoyalty));
    characteristic->Set(String::NewFromUtf8(isolate, "getSquadDiscipline"),  Integer::New(isolate, getSquadDiscipline));
    characteristic->Set(String::NewFromUtf8(isolate, "getFinancialControl"),  Integer::New(isolate, getFinancialControl));
    characteristic->Set(String::NewFromUtf8(isolate, "getMediaHandling"),  Integer::New(isolate, getMediaHandling));
    // below here i am trying to include the object "obj_lvl" into the first object "obj"


    obj->Set(String::NewFromUtf8(isolate, "characteristic"), characteristic);
    */

    args.GetReturnValue().Set(obj);

}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "myProfile", myProfile);
  NODE_SET_METHOD(exports, "currentClub", currentClub);
}

NODE_MODULE(fm19js, init)


