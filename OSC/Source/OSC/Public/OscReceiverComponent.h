#pragma once

#include "Components/ActorComponent.h"
#include "OscReceiverInterface.h"
#include "OscDataElemStruct.h"
#include "OscReceiverComponent.generated.h"


// declare the OnOscReceived event type
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FComponentOscReceivedSignature, const FName &, Address, const TArray<FOscDataElemStruct> &, Data);


UCLASS(ClassGroup=OSC, meta = (BlueprintSpawnableComponent))
class OSC_API UOscReceiverComponent : public UActorComponent
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, Category=OSC)
    FString AddressFilter;

    UPROPERTY(BlueprintAssignable, Category=OSC)
    FComponentOscReceivedSignature OnOscReceived;

public:

    UOscReceiverComponent();

    /// Hot reload constructor
    UOscReceiverComponent(FVTableHelper & helper);

    const FString & GetAddressFilter() const
    {
        return AddressFilter;
    }

    void SendEvent(const FName & Address, const TArray<FOscDataElemStruct> & Data)
    {
        OnOscReceived.Broadcast(Address, Data);
    }

private:
    void OnRegister() override;

    void OnUnregister() override;

private:
    BasicOscReceiver<UOscReceiverComponent> _listener;
};
