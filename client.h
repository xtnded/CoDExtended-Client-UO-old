#define cls_realtime ((int*)0x4AD3E80) // 0x155F3E0)
#define cls_state ((int*)0x4AD3D60)
#define clc_stringData ((PCHAR)0x495E6F4)
#define clc_stringOffsets ((PINT)0x495C6F4)
#define clc_demoplaying ((PINT)0x4DE960C)

#define cs0 (clc_stringData + clc_stringOffsets[0])
#define cs1 (clc_stringData + clc_stringOffsets[1])

static bool unlock_client_structure() {
	return true;
}