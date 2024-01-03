//  Copyright GenericMessagePlugin, Inc. All Rights Reserved.

#include "GMPProtoUtils.h"

void UProtoDescrotor::GetPreloadDependencies(TArray<UObject*>& OutDeps)
{
	Super::GetPreloadDependencies(OutDeps);
	OutDeps.Append(Deps);
}

void UProtoDescrotor::RegisterProto()
{
	if (bRegistered)
		return;
	bRegistered = true;

	for (auto Dep : Deps)
	{
		if (Dep)
		{
			Dep->RegisterProto();
		}
	}

	//
	extern void ReigsterProtoDesc(const char *, size_t);
	ReigsterProtoDesc((const char*)Desc.GetData(), Desc.Num());
}

void UProtoDefinedStruct::PostLoad()
{
	Super::PostLoad();
	if (ProtoDesc)
	{
		ProtoDesc->RegisterProto();
	}
}
