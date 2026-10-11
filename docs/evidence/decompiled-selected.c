/* Static pseudocode. Types/signatures can be wrong. Not original source. */

/* Address 0x1000095e8 */

void candidate_1000095e8(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *param_1;
  if (-1 < lVar1) {
    return;
  }
  lVar2 = (long)param_1 + (long)(int)lVar1;
  _swift_getTypeByMangledNameInContext(lVar2,-(lVar1 >> 0x20),0,0);
  *param_1 = lVar2;
  return;
}


/* Address 0x10000985c */

void candidate_10000985c(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *param_1;
  if (-1 < lVar1) {
    return;
  }
  lVar2 = 0xff;
  _swift_getTypeByMangledNameInContextInMetadataState
            (0xff,(long)param_1 + (long)(int)lVar1,-(lVar1 >> 0x20),0,0);
  *param_1 = lVar2;
  return;
}


/* Address 0x100009960 */

void candidate_100009960(undefined8 param_1,long *param_2,long *param_3)

{
  long lVar1;
  
  if (*param_2 != 0) {
    return;
  }
  lVar1 = *param_3;
  _objc_opt_self();
  _swift_getObjCClassMetadata();
  *param_2 = lVar1;
  return;
}


/* Address 0x100009c1c */

undefined8 candidate_100009c1c(undefined8 param_1,long param_2)

{
  candidate_1000095e8();
  (**(code **)(*(long *)(param_2 + -8) + 8))(param_1,param_2);
  return param_1;
}


/* Address 0x10000e92c */

void candidate_10000e92c(undefined8 *param_1)

{
  if ((*(byte *)(*(long *)(param_1[3] + -8) + 0x52) >> 1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010000e940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(long *)(param_1[3] + -8) + 8))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000100d10b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_release_100fc7b78)(*param_1);
  return;
}


/* Address 0x10000fb20 */

undefined8 * candidate_10000fb20(long param_1,undefined8 *param_2)

{
  if ((*(byte *)(*(long *)(param_1 + -8) + 0x52) >> 1 & 1) != 0) {
    param_2 = (undefined8 *)*param_2;
  }
  return param_2;
}


/* Address 0x1000105b4 */

void candidate_1000105b4(long *param_1,undefined8 param_2,long param_3)

{
  if (*param_1 == 0) {
    candidate_10000985c(param_2);
    _swift_getWitnessTable(param_3,param_2);
    *param_1 = param_3;
  }
  return;
}


/* Address 0x100014e98 */

undefined1  [16] candidate_100014e98(undefined8 param_1,ulong param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined8 uVar9;
  undefined *puVar10;
  ulong uVar11;
  undefined *puVar12;
  undefined *puVar13;
  ulong uVar14;
  long lVar15;
  byte *pbVar16;
  long *plVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  long *plStack_70;
  long lStack_68;
  
  iVar3 = (int)&plStack_70;
  lStack_68 = *(long *)PTR____stack_chk_guard_100fc2d10;
  plStack_70 = (long *)0x0;
  _getifaddrs();
  puVar7 = PTR___ss4Int8VN_100fc7308;
  lVar15 = 0;
  uVar14 = 0;
  if (iVar3 == 0) {
    if (plStack_70 == (long *)0x0) {
      lVar15 = 0;
      uVar14 = 0;
      plVar6 = (long *)0x0;
    }
    else {
      uVar14 = 0;
      lVar15 = 0;
      plVar17 = plStack_70;
      do {
        pbVar16 = (byte *)plVar17[3];
        if (pbVar16 == (byte *)0x0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x1000150c8);
          (*pcVar2)();
        }
        uVar11 = param_2;
        if (pbVar16[1] == 2) {
          uVar4 = plVar17[1];
          if (uVar4 == 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x1000150cc);
            (*pcVar2)();
          }
          FUN_100d0c88c();
          if (((uVar4 == 0x306e65 && param_2 == 0xe300000000000000) ||
              (uVar11 = uVar4, FUN_100d0e7b8(), (uVar11 & 1) != 0)) ||
             ((uVar4 == 0x3070695f706470 && (param_2 == 0xe700000000000000)))) {
            _swift_bridgeObjectRelease(param_2);
          }
          else {
            uVar11 = param_2;
            FUN_100d0e7b8(uVar4,param_2,0x3070695f706470,0xe700000000000000,0);
            _swift_bridgeObjectRelease(param_2);
            if ((uVar4 & 1) == 0) goto LAB_100014f28;
          }
          lVar5 = 0x401;
          FUN_100d0cc10(0x401,puVar7);
          *(undefined8 *)(lVar5 + 0x10) = 0x401;
          _bzero(lVar5 + 0x20,0x401);
          uVar11 = (ulong)*pbVar16;
          _getnameinfo(pbVar16,uVar11,lVar5 + 0x20,0x401,0,0,2);
          if ((int)pbVar16 == 0) {
            _swift_bridgeObjectRelease(uVar14);
            if (*(long *)(lVar5 + 0x10) == 0) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(1,0x1000150c4);
              (*pcVar2)();
            }
            if (*(char *)(lVar5 + 0x20) == '\0') {
              uVar11 = 0;
            }
            else {
              uVar11 = 0;
              do {
                if (*(long *)(lVar5 + 0x10) - 1U == uVar11) {
                    /* WARNING: Does not return */
                  pcVar2 = (code *)SoftwareBreakpoint(1,0x1000150c0);
                  (*pcVar2)();
                }
                pcVar1 = (char *)(lVar5 + 0x21 + uVar11);
                uVar11 = uVar11 + 1;
              } while (*pcVar1 != '\0');
            }
            lVar15 = lVar5 + 0x20;
            FUN_100d0c7b4();
            uVar14 = uVar11;
          }
          _swift_bridgeObjectRelease(lVar5);
        }
LAB_100014f28:
        plVar17 = (long *)*plVar17;
        plVar6 = plStack_70;
        param_2 = uVar11;
      } while (plVar17 != (long *)0x0);
    }
    _freeifaddrs(plVar6);
  }
  if (*(long *)PTR____stack_chk_guard_100fc2d10 != lStack_68) {
    ___stack_chk_fail();
    puVar7 = PTR__OBJC_CLASS___NSUserDefaults_1010d2e00;
    _objc_opt_self();
    puVar8 = puVar7;
    _objc_msgSend();
    _objc_retainAutoreleasedReturnValue();
    uVar9 = 0xd000000000000014;
    FUN_100d0c628(0xd000000000000014,0x8000000100d14210);
    _objc_msgSend(puVar8,PTR_s_integerForKey__1010d2668,uVar9);
    _objc_release_x20();
    _objc_release_x22();
    if (puVar8 == (undefined *)0x1) {
      _objc_msgSend(puVar7,PTR_s_standardUserDefaults_1010d2758);
      _objc_retainAutoreleasedReturnValue();
      uVar9 = 0x2e72656874616546;
      FUN_100d0c628(0x2e72656874616546,0xed00007869467069);
      puVar12 = PTR_s_boolForKey__1010d1be8;
      _objc_msgSend(puVar7,PTR_s_boolForKey__1010d1be8,uVar9);
      puVar10 = puVar7;
      _objc_release_x21();
      _objc_release_x22();
      puVar8 = (undefined *)0x2e302e302e373231;
      puVar13 = (undefined *)0xe900000000000031;
      if ((((ulong)puVar7 & 1) == 0) && (candidate_100014e98(), puVar12 != (undefined *)0x0)) {
        puVar8 = puVar10;
        puVar13 = puVar12;
      }
    }
    else {
      puVar8 = (undefined *)0xd000000000000013;
      puVar13 = (undefined *)0x8000000100d14230;
    }
    auVar19._8_8_ = puVar13;
    auVar19._0_8_ = puVar8;
    return auVar19;
  }
  auVar18._8_8_ = uVar14;
  auVar18._0_8_ = lVar15;
  return auVar18;
}


/* Address 0x1000150d0 */

undefined1  [16] candidate_1000150d0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined1 auVar7 [16];
  
  puVar1 = PTR__OBJC_CLASS___NSUserDefaults_1010d2e00;
  _objc_opt_self();
  puVar2 = puVar1;
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  uVar3 = 0xd000000000000014;
  FUN_100d0c628(0xd000000000000014,0x8000000100d14210);
  _objc_msgSend(puVar2,PTR_s_integerForKey__1010d2668,uVar3);
  _objc_release_x20();
  _objc_release_x22();
  if (puVar2 == (undefined *)0x1) {
    _objc_msgSend(puVar1,PTR_s_standardUserDefaults_1010d2758);
    _objc_retainAutoreleasedReturnValue();
    uVar3 = 0x2e72656874616546;
    FUN_100d0c628(0x2e72656874616546,0xed00007869467069);
    puVar5 = PTR_s_boolForKey__1010d1be8;
    _objc_msgSend(puVar1,PTR_s_boolForKey__1010d1be8,uVar3);
    puVar4 = puVar1;
    _objc_release_x21();
    _objc_release_x22();
    puVar2 = (undefined *)0x2e302e302e373231;
    puVar6 = (undefined *)0xe900000000000031;
    if ((((ulong)puVar1 & 1) == 0) && (candidate_100014e98(), puVar5 != (undefined *)0x0)) {
      puVar2 = puVar4;
      puVar6 = puVar5;
    }
  }
  else {
    puVar2 = (undefined *)0xd000000000000013;
    puVar6 = (undefined *)0x8000000100d14230;
  }
  auVar7._8_8_ = puVar6;
  auVar7._0_8_ = puVar2;
  return auVar7;
}


/* Address 0x1000152b8 */

undefined8 candidate_1000152b8(undefined8 param_1,undefined8 param_2,long param_3)

{
  candidate_1000095e8();
  (**(code **)(*(long *)(param_3 + -8) + 0x10))(param_2,param_1,param_3);
  return param_2;
}


/* Address 0x100015f70 */

ulong candidate_100015f70(ulong param_1,ulong param_2)

{
  char *pcVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_2 >> 0x3e == 0) {
    if ((long)param_1 < 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1000160e4);
      (*pcVar2)();
    }
    if (*(ulong *)((param_2 & 0xffffffffffffff8) + 0x10) <= param_1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1000160e8);
      (*pcVar2)();
    }
    param_1 = *(ulong *)((param_2 & 0xffffffffffffff8) + param_1 * 8 + 0x20);
    candidate_100105178(0);
    uVar4 = param_1;
    _swift_unknownObjectRetain();
    _swift_dynamicCastClass();
    if (uVar4 != 0) {
      return param_1;
    }
    FUN_100d0dc54(0x52);
    pcVar1 = "Down-casted Array element failed to match the target type\nExpected ";
    uVar3 = 0xd000000000000043;
  }
  else {
    uVar4 = param_2 & 0xffffffffffffff8;
    if ((long)param_2 < 0) {
      uVar4 = param_2;
    }
    FUN_100d0e200(param_1,uVar4);
    uVar3 = 0;
    candidate_100105178(0);
    uVar4 = param_1;
    _swift_dynamicCastClass(param_1,uVar3);
    if (uVar4 != 0) {
      return param_1;
    }
    FUN_100d0dc54(0x55);
    pcVar1 = "NSArray element failed to match the Swift Array Element type\nExpected ";
    uVar3 = 0xd000000000000046;
  }
  FUN_100d0c868(uVar3,(ulong)(pcVar1 + -0x20) | 0x8000000000000000);
  FUN_100d0c868(0x6369666974726543,0xef72696150657461);
  FUN_100d0c868(0x756f662074756220,0xeb0000000020646e);
  _swift_getObjectType(param_1);
  uVar3 = 0;
  FUN_100d0eddc();
  FUN_100d0c868();
  _swift_bridgeObjectRelease(uVar3);
  FUN_100d0e164("Fatal error",0xb,2,0,0xe000000000000000,0);
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x1000161a0);
  (*pcVar2)();
}


/* Address 0x100015ffc */

ulong candidate_100015ffc(ulong param_1,ulong param_2,code *param_3,undefined8 param_4,
                         undefined8 param_5)

{
  char *pcVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_2 >> 0x3e == 0) {
    if ((long)param_1 < 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1000160e4);
      (*pcVar2)();
    }
    if (*(ulong *)((param_2 & 0xffffffffffffff8) + 0x10) <= param_1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1000160e8);
      (*pcVar2)();
    }
    param_1 = *(ulong *)((param_2 & 0xffffffffffffff8) + param_1 * 8 + 0x20);
    (*param_3)(0);
    uVar4 = param_1;
    _swift_unknownObjectRetain();
    _swift_dynamicCastClass();
    if (uVar4 != 0) {
      return param_1;
    }
    FUN_100d0dc54(0x52);
    pcVar1 = "Down-casted Array element failed to match the target type\nExpected ";
    uVar3 = 0xd000000000000043;
  }
  else {
    uVar4 = param_2 & 0xffffffffffffff8;
    if ((long)param_2 < 0) {
      uVar4 = param_2;
    }
    FUN_100d0e200(param_1,uVar4);
    uVar3 = 0;
    (*param_3)(0);
    uVar4 = param_1;
    _swift_dynamicCastClass(param_1,uVar3);
    if (uVar4 != 0) {
      return param_1;
    }
    FUN_100d0dc54(0x55);
    pcVar1 = "NSArray element failed to match the Swift Array Element type\nExpected ";
    uVar3 = 0xd000000000000046;
  }
  FUN_100d0c868(uVar3,(ulong)(pcVar1 + -0x20) | 0x8000000000000000);
  FUN_100d0c868(param_4,param_5);
  FUN_100d0c868(0x756f662074756220,0xeb0000000020646e);
  _swift_getObjectType(param_1);
  uVar3 = 0;
  FUN_100d0eddc();
  FUN_100d0c868();
  _swift_bridgeObjectRelease(uVar3);
  FUN_100d0e164("Fatal error",0xb,2,0,0xe000000000000000,0);
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x1000161a0);
  (*pcVar2)();
}


/* Address 0x10001683c */

void candidate_10001683c(void)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (puRam00000001010d5cd0 != (undefined *)0x0) {
    return;
  }
  uVar1 = 0xff;
  FUN_100d0bfe0(0xff);
  puVar2 = PTR___s8Dispatch0A13WorkItemFlagsVs10SetAlgebraAAMc_100fc7e30;
  _swift_getWitnessTable(PTR___s8Dispatch0A13WorkItemFlagsVs10SetAlgebraAAMc_100fc7e30,uVar1);
  puRam00000001010d5cd0 = puVar2;
  return;
}


/* Address 0x1000170e4 */

/* WARNING: Removing unreachable block (ram,0x000100017204) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * candidate_1000170e4(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined *puVar4;
  long lVar5;
  long unaff_x20;
  
  puVar1 = PTR__OBJC_CLASS___NSFetchRequest_1010d2e88;
  _objc_allocWithZone(PTR__OBJC_CLASS___NSFetchRequest_1010d2e88);
  uVar2 = 0x6369666974726543;
  FUN_100d0c628(0x6369666974726543,0xef72696150657461);
  _objc_msgSend(puVar1,PTR_s_initWithEntityName__1010d1c80,uVar2);
  _objc_release_x20();
  lVar3 = 0x1010d64f0;
  candidate_1000095e8();
  _swift_allocObject();
  uVar2 = _UNK_100d65460;
  *(undefined8 *)(lVar3 + 0x18) = _UNK_100d65468;
  *(undefined8 *)(lVar3 + 0x10) = uVar2;
  uVar2 = 0;
  candidate_100017284(0);
  puVar4 = &UNK_100d65478;
  _swift_getKeyPath();
  FUN_100d0d468();
  *(undefined **)(lVar3 + 0x20) = puVar4;
  lVar5 = lVar3;
  FUN_100d0cb98(lVar3,uVar2);
  _swift_bridgeObjectRelease(lVar3);
  _objc_msgSend(puVar1,PTR_s_setSortDescriptors__1010d1c90,lVar5);
  _objc_release_x20();
  _objc_msgSend(*(undefined8 *)(unaff_x20 + 0x10),PTR_s_viewContext_1010d1c28);
  _objc_retainAutoreleasedReturnValue();
  uVar2 = 0;
  candidate_100105178(0);
  FUN_100d0d600(puVar1,uVar2);
  _objc_release_x19();
  _objc_release_x20();
  return puVar1;
}


/* Address 0x100017284 */

void candidate_100017284(void)

{
  undefined *puVar1;
  
  if (puRam00000001010d64f8 != (undefined *)0x0) {
    return;
  }
  puVar1 = PTR__OBJC_CLASS___NSSortDescriptor_1010d2e90;
  _objc_opt_self();
  _swift_getObjCClassMetadata();
  puRam00000001010d64f8 = puVar1;
  return;
}


/* Address 0x100024b38 */

undefined * candidate_100024b38(undefined *param_1,undefined8 param_2,long *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  long lVar4;
  undefined *puStack_60;
  undefined8 uStack_58;
  undefined *puStack_48;
  
  ppuVar2 = &puStack_60;
  _swift_bridgeObjectRetain(param_2);
  candidate_100024c00(&puStack_60,0,0,1,param_1,param_2);
  puVar1 = puStack_60;
  if (ppuVar2 == (undefined **)0x0) {
    lVar4 = *param_3;
    uStack_58 = param_2;
    puStack_60 = param_1;
    puStack_48 = PTR___ss11_StringGutsVN_100fc6660;
  }
  else {
    _swift_bridgeObjectRelease(param_2);
    puVar3 = (undefined *)ppuVar2;
    _swift_getObjectType();
    lVar4 = *param_3;
    puStack_60 = (undefined *)ppuVar2;
    puStack_48 = puVar3;
  }
  if (lVar4 != 0) {
    candidate_100025034(&puStack_60,lVar4);
    *param_3 = lVar4 + 0x20;
  }
  candidate_10000e92c(&puStack_60);
  return puVar1;
}


/* Address 0x100024c00 */

void candidate_100024c00(ulong *param_1,ulong param_2,long param_3,uint param_4,ulong param_5,
                        ulong param_6)

{
  code *pcVar1;
  ulong uVar2;
  ulong uStack_40;
  ulong uStack_38;
  
  if ((param_6 >> 0x3d & 1) == 0) {
    if ((param_6 >> 0x3c & 1) == 0) {
      if ((param_5 >> 0x3c & 1) == 0) {
        FUN_100d0ddd4(param_5,param_6);
        if (param_5 == 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x100024d08);
          (*pcVar1)();
        }
      }
      else {
        param_5 = (param_6 & 0xfffffffffffffff) + 0x20;
      }
      *param_1 = param_5;
      if ((long)param_6 < 0) {
        return;
      }
      _swift_unknownObjectRetain(param_6 & 0xfffffffffffffff);
      return;
    }
  }
  else if ((((param_4 & 1) == 0) && (param_2 != 0)) &&
          (uVar2 = param_6 >> 0x38 & 0xf, (long)uVar2 < (long)(param_3 - param_2))) {
    uStack_38 = param_6 & 0xffffffffffffff;
    uStack_40 = param_5;
    _memcpy(param_2,&uStack_40,uVar2);
    *(undefined1 *)(param_2 + uVar2) = 0;
    *param_1 = param_2;
    return;
  }
  candidate_100024d08(param_5);
  *param_1 = param_6;
  return;
}


/* Address 0x100024d08 */

void candidate_100024d08(void)

{
  func_0x000100024d64();
  candidate_1000095e8(0x1010d6658);
  _swift_initStaticObject();
  func_0x000100024dfc();
  return;
}


/* Address 0x100025034 */

long candidate_100025034(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x18);
  *(long *)(param_2 + 0x18) = lVar1;
  (*(code *)**(undefined8 **)(lVar1 + -8))(param_2,param_1);
  return param_2;
}


/* Address 0x10003cb94 */

void candidate_10003cb94(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 in_x3;
  undefined8 in_x4;
  undefined8 in_x5;
  undefined8 in_x6;
  undefined8 in_x7;
  long unaff_x22;
  undefined8 in_stack_00000000;
  undefined8 in_stack_00000008;
  
  *(undefined8 *)(unaff_x22 + 0x38) = in_stack_00000000;
  *(undefined8 *)(unaff_x22 + 0x40) = in_stack_00000008;
  *(undefined8 *)(unaff_x22 + 0x28) = in_x6;
  *(undefined8 *)(unaff_x22 + 0x30) = in_x7;
  *(undefined8 *)(unaff_x22 + 0x18) = in_x4;
  *(undefined8 *)(unaff_x22 + 0x20) = in_x5;
  *(undefined8 *)(unaff_x22 + 0x10) = in_x3;
  lVar1 = 0;
  FUN_100d0c6d0();
  uVar2 = *(long *)(*(long *)(lVar1 + -8) + 0x40) + 0xfU & 0xfffffffffffffff0;
  _swift_task_alloc();
  *(ulong *)(unaff_x22 + 0x48) = uVar2;
  lVar1 = 0x1010d5d00;
  candidate_1000095e8();
  uVar2 = *(long *)(*(long *)(lVar1 + -8) + 0x40) + 0xf;
  uVar3 = uVar2 & 0xfffffffffffffff0;
  _swift_task_alloc();
  *(ulong *)(unaff_x22 + 0x50) = uVar3;
  uVar2 = uVar2 & 0xfffffffffffffff0;
  _swift_task_alloc();
  *(ulong *)(unaff_x22 + 0x58) = uVar2;
  lVar1 = 0;
  FUN_100d09604();
  *(long *)(unaff_x22 + 0x60) = lVar1;
  lVar1 = *(long *)(lVar1 + -8);
  *(long *)(unaff_x22 + 0x68) = lVar1;
  uVar2 = *(long *)(lVar1 + 0x40) + 0xf;
  uVar3 = uVar2 & 0xfffffffffffffff0;
  _swift_task_alloc();
  *(ulong *)(unaff_x22 + 0x70) = uVar3;
  uVar2 = uVar2 & 0xfffffffffffffff0;
  _swift_task_alloc();
  *(ulong *)(unaff_x22 + 0x78) = uVar2;
                    /* WARNING: Could not recover jumptable at 0x000100d10c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_task_switch_100fc8578)(&DAT_10003cc60,0,0);
  return;
}


/* Address 0x100074ef8 */

void candidate_100074ef8(void)

{
  undefined *puVar1;
  long lVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long extraout_x8;
  
  lVar2 = 0x1010d5cf0;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar2 + -8) + 0x40));
  puVar1 = PTR__OBJC_CLASS___UINotificationFeedbackGenerator_1010d2e30;
  _objc_allocWithZone();
  _objc_msgSend();
  _objc_msgSend();
  lVar2 = 0;
  FUN_100d0cdf0();
  (**(code **)(*(long *)(lVar2 + -8) + 0x38))
            (&stack0xffffffffffffffc0 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0),1,1,lVar2);
  puVar3 = &UNK_100fcbc60;
  _swift_allocObject(&UNK_100fcbc60,0x58,7);
  *(undefined8 *)(puVar3 + 0x10) = 0;
  *(undefined8 *)(puVar3 + 0x18) = 0;
  *(undefined8 *)(puVar3 + 0x20) = 0xd000000000000023;
  *(undefined8 *)(puVar3 + 0x28) = 0x8000000100d15590;
  *(undefined8 *)(puVar3 + 0x30) = 0xd000000000000023;
  *(undefined8 *)(puVar3 + 0x38) = 0x8000000100d155c0;
  *(code **)(puVar3 + 0x40) = candidate_100075038;
  *(undefined8 *)(puVar3 + 0x48) = 0;
  *(undefined **)(puVar3 + 0x50) = puVar1;
  _objc_retain_x20();
  uVar4 = 0;
  candidate_1000e182c(0,0,&stack0xffffffffffffffc0 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0),
                      &UNK_100d67310,puVar3);
  _objc_release_x20();
  _swift_release(uVar4);
  return;
}


/* Address 0x100075038 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void candidate_100075038(ulong param_1)

{
  long lVar1;
  long lVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long extraout_x8;
  long extraout_x8_00;
  undefined1 *puVar7;
  long lVar8;
  long lVar9;
  undefined1 auStack_a0 [8];
  long lStack_98;
  undefined *puStack_90;
  undefined8 uStack_88;
  undefined *puStack_80;
  undefined *puStack_78;
  undefined *puStack_70;
  undefined8 uStack_68;
  
  lVar1 = 0;
  FUN_100d0bfe0();
  lStack_98 = *(long *)(lVar1 + -8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lStack_98 + 0x40));
  puVar7 = auStack_a0 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0);
  lVar2 = 0;
  FUN_100d0c034();
  lVar9 = *(long *)(lVar2 + -8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lVar9 + 0x40));
  lVar8 = (long)puVar7 - (extraout_x8_00 + 0xfU & 0xfffffffffffffff0);
  candidate_100009960(0,0x1010d5cc8,&PTR__OBJC_CLASS___OS_dispatch_queue_1010d2e28);
  FUN_100d0d4e0();
  if ((param_1 & 1) == 0) {
    puStack_70 = &DAT_1000753b8;
    puStack_78 = &UNK_100fcbc78;
  }
  else {
    puStack_70 = &DAT_100075244;
    puStack_78 = &UNK_100fcbca0;
  }
  uStack_68 = 0;
  uStack_88 = _UNK_100d64030;
  puStack_90 = PTR___NSConcreteStackBlock_100fc2c68;
  puStack_80 = &DAT_100020804;
  ppuVar3 = &puStack_90;
  __Block_copy(ppuVar3);
  ppuVar4 = ppuVar3;
  FUN_100d0c004(lVar8);
  puStack_90 = PTR___swiftEmptyArrayStorage_100fc7890;
  candidate_10001683c();
  uVar5 = 0x1010d5cd8;
  candidate_1000095e8(0x1010d5cd8);
  uVar6 = 0x1010d5ce0;
  candidate_1000105b4(0x1010d5ce0,0x1010d5cd8,PTR___sSayxGSTsMc_100fc5d10);
  FUN_100d0db10(puVar7,&puStack_90,uVar5,uVar6,lVar1,ppuVar4);
  FUN_100d0d4f8(0,lVar8,puVar7,ppuVar3);
  __Block_release(ppuVar3);
  _objc_release_x24();
  (**(code **)(lStack_98 + 8))(puVar7,lVar1);
  (**(code **)(lVar9 + 8))(lVar8,lVar2);
  return;
}


/* Address 0x100075588 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void candidate_100075588(void)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  long unaff_x20;
  long lVar12;
  long unaff_x22;
  
  uVar1 = *(undefined8 *)(unaff_x20 + 0x10);
  uVar4 = *(undefined8 *)(unaff_x20 + 0x18);
  lVar8 = *(long *)(unaff_x20 + 0x20);
  lVar5 = *(long *)(unaff_x20 + 0x28);
  lVar2 = *(long *)(unaff_x20 + 0x30);
  lVar6 = *(long *)(unaff_x20 + 0x38);
  lVar3 = *(long *)(unaff_x20 + 0x40);
  lVar7 = *(long *)(unaff_x20 + 0x48);
  lVar12 = *(long *)(unaff_x20 + 0x50);
  plVar11 = (long *)(ulong)_UNK_100d66084;
  _swift_task_alloc();
  *(long **)(unaff_x22 + 0x10) = plVar11;
  *plVar11 = unaff_x22;
  plVar11[1] = (long)&DAT_100009b94;
  plVar11[7] = lVar7;
  plVar11[8] = lVar12;
  plVar11[5] = lVar6;
  plVar11[6] = lVar3;
  plVar11[3] = lVar5;
  plVar11[4] = lVar2;
  plVar11[2] = lVar8;
  lVar8 = 0;
  FUN_100d0c6d0(0,uVar1,uVar4);
  uVar9 = *(long *)(*(long *)(lVar8 + -8) + 0x40) + 0xfU & 0xfffffffffffffff0;
  _swift_task_alloc();
  plVar11[9] = uVar9;
  lVar8 = 0x1010d5d00;
  candidate_1000095e8();
  uVar9 = *(long *)(*(long *)(lVar8 + -8) + 0x40) + 0xf;
  uVar10 = uVar9 & 0xfffffffffffffff0;
  _swift_task_alloc();
  plVar11[10] = uVar10;
  uVar9 = uVar9 & 0xfffffffffffffff0;
  _swift_task_alloc();
  plVar11[0xb] = uVar9;
  lVar8 = 0;
  FUN_100d09604();
  plVar11[0xc] = lVar8;
  lVar8 = *(long *)(lVar8 + -8);
  plVar11[0xd] = lVar8;
  uVar9 = *(long *)(lVar8 + 0x40) + 0xf;
  uVar10 = uVar9 & 0xfffffffffffffff0;
  _swift_task_alloc();
  plVar11[0xe] = uVar10;
  uVar9 = uVar9 & 0xfffffffffffffff0;
  _swift_task_alloc();
  plVar11[0xf] = uVar9;
                    /* WARNING: Could not recover jumptable at 0x000100d10c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_task_switch_100fc8578)(&DAT_10003cc60,0,0);
  return;
}


/* Address 0x10007cdd0 */

undefined1  [16] candidate_10007cdd0(void)

{
  undefined8 uVar1;
  long lVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  long extraout_x8;
  long extraout_x12;
  code *pcVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 *puVar12;
  undefined1 auVar13 [16];
  undefined *apuStack_80 [2];
  undefined8 uStack_70;
  long lStack_68;
  
  lStack_68 = *(long *)PTR____stack_chk_guard_100fc2d10;
  lVar2 = 0;
  FUN_100d09de4();
  lVar10 = *(long *)(lVar2 + -8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lVar10 + 0x40));
  lVar9 = (long)apuStack_80 - (extraout_x8 + 0xfU & 0xfffffffffffffff0);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar8 = lVar9 - extraout_x12;
  puVar3 = PTR__OBJC_CLASS___NSFileManager_1010d2e48;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_s_temporaryDirectory_1010d1b50;
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  FUN_100d09d6c(lVar8);
  _objc_release_x20();
  uVar4 = 1;
  FUN_100d09d90(1);
  FUN_100d0c628();
  _swift_bridgeObjectRelease(puVar5);
  uStack_70 = 0;
  puVar5 = puVar3;
  _objc_msgSend(puVar3,PTR_s_contentsOfDirectoryAtPath_error__1010d1f10,uVar4,&uStack_70);
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x21();
  uVar4 = uStack_70;
  if (puVar5 == (undefined *)0x0) {
    _objc_retain_x21();
    FUN_100d09c88(uVar4);
    _objc_release_x20();
    _swift_willThrow();
    _objc_release_x23();
    _swift_errorRelease(uVar4);
    (**(code **)(lVar10 + 8))(lVar8,lVar2);
  }
  else {
    FUN_100d0cba4(puVar5,PTR___sSSN_100fc5a40);
    _objc_retain_x21();
    _objc_release_x20();
    lVar11 = *(long *)(puVar5 + 0x10);
    if (lVar11 == 0) {
      _swift_bridgeObjectRelease(puVar5);
      _objc_release_x23();
      pcVar7 = *(code **)(lVar10 + 8);
    }
    else {
      puVar12 = (undefined8 *)(puVar5 + 0x28);
      apuStack_80[0] = puVar5;
      do {
        uVar4 = puVar12[-1];
        uVar1 = *puVar12;
        _swift_bridgeObjectRetain(uVar1);
        uVar6 = uVar1;
        FUN_100d09d3c(lVar9,uVar4,uVar1);
        _swift_bridgeObjectRelease(uVar1);
        uVar4 = 1;
        FUN_100d09d90(1);
        pcVar7 = *(code **)(lVar10 + 8);
        (*pcVar7)(lVar9,lVar2);
        FUN_100d0c628(uVar4,uVar6);
        _swift_bridgeObjectRelease(uVar6);
        uStack_70 = 0;
        puVar5 = puVar3;
        _objc_msgSend(puVar3,PTR_s_removeItemAtPath_error__1010d1f18,uVar4,&uStack_70);
        _objc_release_x20();
        uVar4 = uStack_70;
        if ((int)puVar5 == 0) {
          _objc_retain_x20();
          FUN_100d09c88(uVar4);
          _objc_release_x21();
          _swift_willThrow();
          _swift_errorRelease(uVar4);
        }
        else {
          _objc_retain_x20();
        }
        puVar12 = puVar12 + 2;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      _swift_bridgeObjectRelease(apuStack_80[0]);
      _objc_release_x23();
    }
    (*pcVar7)(lVar8,lVar2);
  }
  if (*(long *)PTR____stack_chk_guard_100fc2d10 == lStack_68) {
    auVar13._8_8_ = lVar2;
    auVar13._0_8_ = lVar8;
    return auVar13;
  }
  ___stack_chk_fail();
  return ZEXT816(0x100fcc110);
}


/* Address 0x1000e182c */

void candidate_1000e182c(long param_1,long param_2,undefined8 param_3,undefined8 param_4,
                        ulong param_5)

{
  long lVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  long extraout_x8;
  undefined1 *puVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  undefined1 auStack_c0 [8];
  undefined8 uStack_b8;
  undefined8 *puStack_b0;
  long lStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  long lStack_90;
  long lStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long lStack_70;
  long lStack_68;
  
  lVar1 = 0x1010d5cf0;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar1 + -8) + 0x40));
  puVar5 = auStack_c0 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0);
  candidate_1000152b8(param_3,puVar5,0x1010d5cf0);
  lVar1 = 0;
  FUN_100d0cdf0();
  lVar8 = *(long *)(lVar1 + -8);
  puVar2 = puVar5;
  (**(code **)(lVar8 + 0x30))(puVar5,1,lVar1);
  uVar7 = param_5;
  _swift_retain(param_5);
  if ((int)puVar2 == 1) {
    candidate_100009c1c(puVar5,0x1010d5cf0);
    uVar7 = 0x1c00;
  }
  else {
    FUN_100d0cde4();
    (**(code **)(lVar8 + 8))(puVar5,lVar1);
    uVar7 = uVar7 & 0xff | 0x1c00;
  }
  lVar1 = *(long *)(param_5 + 0x10);
  lVar8 = *(long *)(param_5 + 0x18);
  _swift_unknownObjectRetain(lVar1);
  _swift_release(param_5);
  if (lVar1 == 0) {
    lVar6 = 0;
    lVar8 = 0;
  }
  else {
    lVar6 = lVar1;
    _swift_getObjectType();
    FUN_100d0ccf4();
    _swift_unknownObjectRelease(lVar1);
  }
  if (param_2 == 0) {
    candidate_100009c1c(param_3,0x1010d5cf0);
    puVar3 = &UNK_100fcdbc8;
    _swift_allocObject(&UNK_100fcdbc8,0x20,7);
    *(undefined8 *)(puVar3 + 0x10) = param_4;
    *(ulong *)(puVar3 + 0x18) = param_5;
    if (lVar8 == 0 && lVar6 == 0) {
      puVar4 = (undefined8 *)0x0;
    }
    else {
      uStack_80 = 0;
      uStack_78 = 0;
      puVar4 = &uStack_80;
      lStack_70 = lVar6;
      lStack_68 = lVar8;
    }
    _swift_task_create(uVar7,puVar4,PTR___sytN_100fc7880 + 8,&UNK_100d66b58,puVar3);
  }
  else {
    FUN_100d0c700(param_1,param_2);
    puVar3 = &UNK_100fcdbf0;
    _swift_allocObject(&UNK_100fcdbf0,0x20,7);
    *(undefined8 *)(puVar3 + 0x10) = param_4;
    *(ulong *)(puVar3 + 0x18) = param_5;
    _swift_retain(param_5);
    if (lVar8 == 0 && lVar6 == 0) {
      puStack_b0 = (undefined8 *)0x0;
    }
    else {
      uStack_a0 = 0;
      uStack_98 = 0;
      puStack_b0 = &uStack_a0;
      lStack_90 = lVar6;
      lStack_88 = lVar8;
    }
    uStack_b8 = 7;
    lStack_a8 = param_1 + 0x20;
    _swift_task_create(uVar7,&uStack_b8,PTR___sytN_100fc7880 + 8,&UNK_100d69080,puVar3);
    _swift_release(param_1);
    candidate_100009c1c(param_3,0x1010d5cf0);
    _swift_bridgeObjectRelease(param_2);
    _swift_release(param_5);
  }
  return;
}


/* Address 0x100103a5c */

/* WARNING: Removing unreachable block (ram,0x000100103c9c) */
/* WARNING: Removing unreachable block (ram,0x000100103c2c) */
/* WARNING: Removing unreachable block (ram,0x000100103c64) */
/* WARNING: Removing unreachable block (ram,0x000100103ce0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void candidate_100103a5c(void)

{
  long lVar1;
  byte bVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long extraout_x8;
  long extraout_x12;
  long lVar6;
  long lVar7;
  undefined1 *puVar8;
  code *pcVar9;
  code *pcVar10;
  long lVar11;
  undefined1 auStack_80 [8];
  long lStack_78;
  long lStack_70;
  
  lVar4 = 0;
  FUN_100d09de4();
  lVar7 = *(long *)(lVar4 + -8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lVar7 + 0x40));
  puVar8 = auStack_80 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar6 = (long)puVar8 - extraout_x12;
  _objc_opt_self(PTR__OBJC_CLASS___NSFileManager_1010d2e48);
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  lVar5 = 0x1010d64e0;
  candidate_1000095e8();
  lVar11 = *(long *)(lVar7 + 0x48);
  bVar2 = *(byte *)(lVar7 + 0x50);
  _swift_allocObject();
  uVar3 = _UNK_100d653d0;
  *(undefined8 *)(lVar5 + 0x18) = _UNK_100d653d8;
  *(undefined8 *)(lVar5 + 0x10) = uVar3;
  lVar1 = lVar5 + ((ulong)bVar2 + 0x20 & ((ulong)bVar2 ^ 0xffffffffffffffff));
  lStack_70 = lVar5;
  FUN_100d09d0c(lVar6);
  FUN_100d09d3c(lVar1,0x7365766968637241,0xe800000000000000);
  pcVar10 = *(code **)(lVar7 + 8);
  (*pcVar10)(lVar6,lVar4);
  FUN_100d09d0c(lVar6);
  FUN_100d09d3c(lVar1 + lVar11,0x6369666974726543,0xec00000073657461);
  (*pcVar10)(lVar6,lVar4);
  FUN_100d09d0c(lVar6);
  FUN_100d09d3c(lVar1 + lVar11 * 2,0x64656e676953,0xe600000000000000);
  (*pcVar10)(lVar6,lVar4);
  FUN_100d09d0c(lVar6);
  lStack_78 = lVar11 * 3;
  FUN_100d09d3c(lVar1 + lVar11 * 3,0x64656e6769736e55,0xe800000000000000);
  (*pcVar10)(lVar6,lVar4);
  pcVar9 = *(code **)(lVar7 + 0x10);
  (*pcVar9)(puVar8,lVar1,lVar4);
  func_0x000100119320(puVar8);
  (*pcVar10)(puVar8,lVar4);
  (*pcVar9)(puVar8,lVar1 + lVar11,lVar4);
  func_0x000100119320(puVar8);
  (*pcVar10)(puVar8,lVar4);
  (*pcVar9)(puVar8,lVar1 + lVar11 * 2,lVar4);
  func_0x000100119320(puVar8);
  (*pcVar10)(puVar8,lVar4);
  (*pcVar9)(puVar8,lVar1 + lStack_78,lVar4);
  _swift_bridgeObjectRelease(lStack_70);
  func_0x000100119320(puVar8);
  _objc_release_x23();
  (*pcVar10)(puVar8,lVar4);
  return;
}


/* Address 0x100103d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ** candidate_100103d20(void)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  long lVar7;
  undefined *puVar8;
  long lVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  long extraout_x8;
  long lVar14;
  long extraout_x8_00;
  long extraout_x8_01;
  long extraout_x12;
  long extraout_x12_00;
  long extraout_x12_01;
  long extraout_x12_02;
  long extraout_x12_03;
  long extraout_x12_04;
  long extraout_x12_05;
  undefined **ppuVar15;
  undefined **ppuVar16;
  undefined **ppuVar17;
  undefined **ppuVar18;
  undefined *puVar19;
  undefined **ppuVar20;
  undefined **ppuVar21;
  undefined **unaff_x24;
  undefined **ppuVar22;
  undefined *puVar23;
  undefined **ppuVar24;
  undefined *apuStack_1d0 [8];
  undefined *puStack_190;
  long lStack_188;
  ulong uStack_180;
  ulong uStack_178;
  ulong uStack_170;
  ulong uStack_168;
  long lStack_160;
  long lStack_158;
  long lStack_150;
  undefined **ppuStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  long lStack_128;
  long lStack_120;
  long lStack_118;
  long lStack_110;
  undefined **ppuStack_108;
  long lStack_100;
  long lStack_f8;
  undefined **ppuStack_f0;
  char *pcStack_e8;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined **ppuStack_d0;
  undefined *puStack_c8;
  undefined *puStack_c0;
  long lStack_b8;
  long lStack_b0;
  long lStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined **ppuStack_90;
  long lStack_88;
  undefined **ppuStack_78;
  long lStack_70;
  
  lStack_70 = *(long *)PTR____stack_chk_guard_100fc2d10;
  lVar3 = 0x1010d5cf0;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar3 + -8) + 0x40));
  lVar14 = (long)&puStack_190 - (extraout_x8 + 0xfU & 0xfffffffffffffff0);
  lStack_118 = lVar14;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar14 - extraout_x12;
  lVar3 = 0;
  lStack_100 = lVar14;
  FUN_100d0c6d0();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar3 + -8) + 0x40));
  lVar14 = lVar14 - (extraout_x8_00 + 0xfU & 0xfffffffffffffff0);
  ppuVar4 = (undefined **)0x0;
  lStack_110 = lVar14;
  FUN_100d09de4();
  puVar19 = ppuVar4[-1];
  ppuVar18 = *(undefined ***)(puVar19 + 0x40);
  ppuVar17 = ppuVar4;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar14 - ((long)ppuVar18 + 0xfU & 0xfffffffffffffff0);
  lStack_120 = lVar14;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar14 - extraout_x12_00;
  lStack_128 = lVar14;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar14 - extraout_x12_01;
  lStack_b0 = lVar14;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar14 - extraout_x12_02;
  lStack_a8 = lVar14;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar14 - extraout_x12_03;
  lStack_b8 = lVar14;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  ppuVar24 = (undefined **)(lVar14 - extraout_x12_04);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  ppuVar16 = (undefined **)((long)ppuVar24 - extraout_x12_05);
  if (lRam00000001010d4b50 != -1) {
    ppuVar17 = (undefined **)0x1010d4b50;
    _swift_once(0x1010d4b50,&DAT_1000152fc);
  }
  ppuStack_108 = ppuVar16;
  candidate_1000170e4();
  ppuVar22 = (undefined **)((ulong)ppuVar17 & 0xffffffffffffff8);
  ppuStack_d0 = ppuVar4;
  puStack_c0 = puVar19;
  if ((ulong)ppuVar17 >> 0x3e == 0) {
    ppuVar4 = ppuVar17;
    ppuVar20 = (undefined **)ppuVar22[2];
  }
  else {
    ppuVar4 = ppuVar22;
    if ((long)ppuVar17 < 0) {
      ppuVar4 = ppuVar17;
    }
    FUN_100d0e1e8();
    ppuVar20 = ppuVar4;
  }
  ppuVar21 = (undefined **)0x0;
  ppuVar15 = &PTR_DAT_1010d1000;
  do {
    ppuVar6 = ppuVar4;
    if (ppuVar20 == ppuVar21) {
      _swift_bridgeObjectRelease(ppuVar17);
      ppuVar20 = (undefined **)PTR__OBJC_CLASS___NSBundle_1010d2dd8;
      _objc_opt_self();
      _objc_msgSend();
      _objc_retainAutoreleasedReturnValue();
      ppuVar21 = (undefined **)0x2d676e696e676973;
      FUN_100d0c628(0x2d676e696e676973,0xee00737465737361);
      ppuVar22 = ppuVar20;
      _objc_msgSend(ppuVar20,PTR_s_URLForResource_withExtension__1010d1bf8,ppuVar21,0);
      _objc_retainAutoreleasedReturnValue();
      ppuVar6 = ppuVar22;
      _objc_release_x22();
      _objc_release_x23();
      puVar19 = puStack_c0;
      ppuVar4 = ppuStack_108;
      ppuVar17 = (undefined **)0x0;
      if (ppuVar22 == (undefined **)0x0) goto LAB_100104908;
      FUN_100d09d6c(ppuStack_108,ppuVar22);
      _objc_release_x20();
      unaff_x24 = (undefined **)PTR__OBJC_CLASS___NSFileManager_1010d2e48;
      _objc_opt_self();
      ppuVar17 = unaff_x24;
      _objc_msgSend();
      _objc_retainAutoreleasedReturnValue();
      ppuVar21 = ppuVar17;
      FUN_100d09d18();
      ppuStack_78 = (undefined **)0x0;
      _objc_msgSend(ppuVar17,PTR_s_contentsOfDirectoryAtURL_includi_1010d1d88,ppuVar21,0,4,
                    &ppuStack_78);
      _objc_retainAutoreleasedReturnValue();
      _objc_release_x22();
      _objc_release_x23();
      ppuVar20 = ppuStack_78;
      ppuVar22 = ppuStack_d0;
      if (ppuVar17 == (undefined **)0x0) {
        _objc_retain_x22();
        unaff_x24 = ppuVar20;
        FUN_100d09c88();
        _objc_release_x20();
        _swift_willThrow();
        ppuVar22 = ppuStack_d0;
        goto LAB_1001047d0;
      }
      ppuVar21 = ppuVar17;
      FUN_100d0cba4(ppuVar17,ppuStack_d0);
      _objc_retain_x22();
      _objc_release_x20();
      puStack_c8 = ppuVar21[2];
      if (puStack_c8 != (undefined *)0x0) {
        puVar23 = (undefined *)0x0;
        ppuStack_148 = (undefined **)0x0;
        uStack_168 = (ulong)(byte)puVar19[0x50];
        uStack_170 = uStack_168 + 0x20 & (uStack_168 ^ 0xffffffffffffffff);
        lVar3 = (long)ppuVar21 + uStack_170;
        pcStack_e8 = ".mobileprovision";
        uStack_178 = (long)ppuVar18 + uStack_170 + uStack_168 & (uStack_168 ^ 0xffffffffffffffff);
        uStack_180 = (long)ppuVar18 + uStack_178 + 7 & 0xfffffffffffffff8;
        lStack_188 = uStack_180 + 0x10;
        puStack_190 = (undefined *)(uStack_180 + 0x28);
        uStack_138 = 0;
        uStack_140 = _UNK_100d65520;
        lStack_f8 = lVar3;
        ppuStack_f0 = unaff_x24;
        ppuStack_e0 = ppuVar21;
        goto LAB_100104188;
      }
      _swift_bridgeObjectRelease(ppuVar21);
      goto LAB_1001048f8;
    }
    if (((ulong)ppuVar17 & 0xc000000000000001) == 0) {
      if (ppuVar22[2] <= ppuVar21) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x100104948);
        (*pcVar2)();
      }
      _objc_retain_x8(ppuVar17[(long)ppuVar21 + 4]);
    }
    else {
      ppuVar6 = ppuVar21;
      candidate_100015f70(ppuVar21,ppuVar17);
    }
    if (SCARRY8((long)ppuVar21,1)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x100104944);
      (*pcVar2)();
    }
    ppuVar5 = ppuVar6;
    _objc_msgSend(ppuVar6,PTR_s_isDefault_1010d1ef8);
    ppuVar4 = ppuVar5;
    _objc_release_x24();
    ppuVar21 = (undefined **)((long)ppuVar21 + 1);
    unaff_x24 = ppuVar6;
  } while ((int)ppuVar5 == 0);
  if (*(long *)PTR____stack_chk_guard_100fc2d10 == lStack_70) {
                    /* WARNING: Could not recover jumptable at 0x000100d1074c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR__swift_bridgeObjectRelease_100fc7928)(ppuVar17);
    return ppuVar17;
  }
  goto LAB_1001049ec;
LAB_100104188:
  do {
    if (ppuVar21[2] <= puVar23) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1001049a8);
      (*pcVar2)();
    }
    ppuVar20 = *(undefined ***)(puVar19 + 0x10);
    ppuVar18 = (undefined **)(lVar3 + *(long *)(puVar19 + 0x48) * (long)puVar23);
    ppuVar17 = ppuVar24;
    (*(code *)ppuVar20)(ppuVar24,ppuVar18,ppuVar22);
    FUN_100d09cf4();
    if (((ulong)ppuVar17 & 1) != 0) {
      FUN_100d09d00();
      ppuStack_d8 = ppuVar17;
      FUN_100d09d3c(lStack_b8,0x3231702e74726563,0xe800000000000000);
      FUN_100d09d3c(lStack_a8,0xd000000000000014,(ulong)pcStack_e8 | 0x8000000000000000);
      FUN_100d09d3c(lStack_b0,0x7478742e74726563,0xe800000000000000);
      ppuVar17 = unaff_x24;
      puVar19 = PTR_s_defaultManager_1010d1b48;
      _objc_msgSend(unaff_x24,PTR_s_defaultManager_1010d1b48);
      _objc_retainAutoreleasedReturnValue();
      ppuVar4 = ppuVar17;
      FUN_100d09d9c();
      FUN_100d0c628();
      _swift_bridgeObjectRelease(puVar19);
      _objc_msgSend(ppuVar17,PTR_s_fileExistsAtPath__1010d1c00,ppuVar4);
      _objc_release_x21();
      _objc_release_x24();
      if ((int)ppuVar17 == 0) {
LAB_1001044dc:
        if (lRam00000001010d4b68 != -1) {
          _swift_once(0x1010d4b68,&DAT_100018dcc);
        }
        FUN_100d0a324(0);
        candidate_10000fb20();
        ppuVar17 = ppuVar18;
        _swift_bridgeObjectRetain();
        FUN_100d0a30c();
        ppuVar4 = ppuVar17;
        FUN_100d0d444();
        _swift_bridgeObjectRelease(ppuVar18);
        ppuVar21 = ppuVar17;
        _os_log_type_enabled(ppuVar17,(uint)ppuVar4 & 0xff);
        puVar19 = puStack_c0;
        ppuVar22 = ppuStack_d0;
        if ((int)ppuVar21 == 0) {
          _swift_bridgeObjectRelease(ppuVar18);
        }
        else {
          puVar10 = (undefined4 *)0xc;
          _swift_slowAlloc(0xc,0xffffffffffffffff);
          ppuVar21 = (undefined **)0x20;
          _swift_slowAlloc(0x20,0xffffffffffffffff);
          *puVar10 = (int)uStack_140;
          ppuVar20 = ppuStack_d8;
          ppuStack_78 = ppuVar21;
          candidate_100024b38(ppuStack_d8,ppuVar18,&ppuStack_78);
          _swift_bridgeObjectRelease(ppuVar18);
          *(undefined ***)(puVar10 + 1) = ppuVar20;
          __os_log_impl(0x100000000,ppuVar17,(uint)ppuVar4 & 0xff,
                        "Skipping %s: missing required files",puVar10,0xc);
          candidate_10000e92c(ppuVar21);
          puVar19 = puStack_c0;
          _swift_slowDealloc(ppuVar21,0xffffffffffffffff,0xffffffffffffffff);
          _swift_slowDealloc(puVar10,0xffffffffffffffff,0xffffffffffffffff);
        }
        _objc_release_x20();
        pcVar2 = *(code **)(puVar19 + 8);
        (*pcVar2)(lStack_b0,ppuVar22);
        (*pcVar2)(lStack_a8,ppuVar22);
        (*pcVar2)(lStack_b8,ppuVar22);
        (*pcVar2)(ppuVar24,ppuVar22);
        lVar3 = lStack_f8;
        ppuVar21 = ppuStack_e0;
        unaff_x24 = ppuStack_f0;
        goto LAB_100104178;
      }
      ppuVar17 = unaff_x24;
      puVar19 = PTR_s_defaultManager_1010d1b48;
      _objc_msgSend(unaff_x24,PTR_s_defaultManager_1010d1b48);
      _objc_retainAutoreleasedReturnValue();
      ppuVar4 = ppuVar17;
      FUN_100d09d9c();
      FUN_100d0c628();
      _swift_bridgeObjectRelease(puVar19);
      _objc_msgSend(ppuVar17,PTR_s_fileExistsAtPath__1010d1c00,ppuVar4);
      _objc_release_x21();
      _objc_release_x24();
      if ((int)ppuVar17 == 0) goto LAB_1001044dc;
      puVar19 = PTR_s_defaultManager_1010d1b48;
      _objc_msgSend(unaff_x24,PTR_s_defaultManager_1010d1b48);
      _objc_retainAutoreleasedReturnValue();
      ppuVar17 = unaff_x24;
      FUN_100d09d9c();
      FUN_100d0c628();
      _swift_bridgeObjectRelease(puVar19);
      _objc_msgSend(unaff_x24,PTR_s_fileExistsAtPath__1010d1c00,ppuVar17);
      _objc_release_x21();
      _objc_release_x24();
      lVar3 = lStack_110;
      if ((int)unaff_x24 == 0) goto LAB_1001044dc;
      FUN_100d0c6a0(lStack_110);
      ppuVar17 = ppuStack_148;
      lVar14 = lStack_b0;
      FUN_100d0c61c();
      ppuStack_148 = ppuVar17;
      if (ppuVar17 == (undefined **)0x0) {
        lVar7 = 0;
        lStack_158 = lVar3;
        lStack_150 = lVar14;
        FUN_100d0cdf0();
        lStack_160 = *(long *)(lVar7 + -8);
        (**(code **)(lStack_160 + 0x38))(lStack_100,1,1,lVar7);
        ppuVar22 = ppuStack_d0;
        lVar3 = lStack_128;
        (*(code *)ppuVar20)(lStack_128,lStack_b8,ppuStack_d0);
        lVar14 = lStack_120;
        (*(code *)ppuVar20)(lStack_120,lStack_a8,ppuVar22);
        puVar19 = puStack_190;
        puVar8 = &UNK_100fce7e0;
        _swift_allocObject(&UNK_100fce7e0,puStack_190 + 0x10,uStack_168 | 7);
        *(undefined8 *)(puVar8 + 0x10) = 0;
        *(undefined8 *)(puVar8 + 0x18) = 0;
        pcVar2 = *(code **)(puStack_c0 + 0x20);
        (*pcVar2)(puVar8 + uStack_170,lVar3,ppuVar22);
        lVar3 = lStack_160;
        (*pcVar2)(puVar8 + uStack_178,lVar14,ppuVar22);
        lVar14 = lStack_118;
        *(long *)(puVar8 + uStack_180) = lStack_150;
        *(long *)((long)(puVar8 + uStack_180) + 8) = lStack_158;
        plVar1 = (long *)(puVar8 + lStack_188);
        *plVar1 = (long)ppuStack_d8;
        plVar1[1] = (long)ppuVar18;
        *(undefined1 *)(plVar1 + 2) = 1;
        *(undefined **)(puVar8 + (long)puVar19) =
             &__sSp21NIOConcurrencyHelpersE20assertValidAlignmentyyF;
        *(undefined8 *)((long)(puVar8 + (long)puVar19) + 8) = 0;
        candidate_1000152b8(lStack_100,lStack_118,0x1010d5cf0);
        lVar9 = lVar14;
        (**(code **)(lVar3 + 0x30))(lVar14,1,lVar7);
        puVar19 = puVar8;
        _swift_retain();
        if ((int)lVar9 == 1) {
          candidate_100009c1c(lVar14,0x1010d5cf0);
          ppuVar20 = (undefined **)0x1000;
        }
        else {
          FUN_100d0cde4();
          (**(code **)(lVar3 + 8))(lVar14,lVar7);
          ppuVar20 = (undefined **)((ulong)puVar19 & 0xff | 0x1000);
        }
        ppuVar18 = *(undefined ***)(puVar8 + 0x10);
        lVar3 = *(long *)(puVar8 + 0x18);
        _swift_unknownObjectRetain(ppuVar18);
        _swift_release(puVar8);
        puVar19 = puStack_c0;
        if (ppuVar18 == (undefined **)0x0) {
          ppuVar17 = (undefined **)0x0;
          lVar3 = 0;
        }
        else {
          ppuVar17 = ppuVar18;
          _swift_getObjectType();
          FUN_100d0ccf4();
          _swift_unknownObjectRelease(ppuVar18);
        }
        unaff_x24 = ppuStack_f0;
        puVar11 = &UNK_100fce808;
        _swift_allocObject(&UNK_100fce808,0x20,7);
        ppuVar21 = ppuStack_e0;
        *(undefined **)(puVar11 + 0x10) = &UNK_100d69910;
        *(undefined **)(puVar11 + 0x18) = puVar8;
        if (lVar3 == 0 && ppuVar17 == (undefined **)0x0) {
          puVar13 = (undefined8 *)0x0;
        }
        else {
          uStack_a0 = 0;
          uStack_98 = 0;
          puVar13 = &uStack_a0;
          ppuStack_90 = ppuVar17;
          lStack_88 = lVar3;
        }
        _swift_task_create(ppuVar20,puVar13,PTR___sytN_100fc7880 + 8,&UNK_100d69918,puVar11);
        _swift_release();
        candidate_100009c1c(lStack_100,0x1010d5cf0);
        pcVar2 = *(code **)(puVar19 + 8);
        (*pcVar2)(lStack_b0,ppuVar22);
        (*pcVar2)(lStack_a8,ppuVar22);
        (*pcVar2)(lStack_b8,ppuVar22);
        (*pcVar2)(ppuVar24,ppuVar22);
        lVar3 = lStack_f8;
        goto LAB_100104178;
      }
      _swift_bridgeObjectRelease(ppuVar18);
      _swift_bridgeObjectRelease(ppuStack_e0);
      puVar19 = puStack_c0;
      ppuVar22 = ppuStack_d0;
      pcVar2 = *(code **)(puStack_c0 + 8);
      (*pcVar2)(lStack_b0,ppuStack_d0);
      (*pcVar2)(lStack_a8,ppuVar22);
      (*pcVar2)(lStack_b8,ppuVar22);
      (*pcVar2)(ppuVar24,ppuVar22);
      ppuVar4 = ppuStack_108;
      ppuVar21 = ppuVar18;
      unaff_x24 = ppuStack_148;
LAB_1001047d0:
      if (lRam00000001010d4b68 != -1) {
        _swift_once(0x1010d4b68,&DAT_100018dcc);
      }
      FUN_100d0a324(0);
      candidate_10000fb20();
      ppuVar17 = unaff_x24;
      _swift_errorRetain();
      FUN_100d0a30c();
      ppuVar18 = ppuVar17;
      FUN_100d0d444();
      _swift_errorRelease(unaff_x24);
      ppuVar24 = ppuVar17;
      _os_log_type_enabled(ppuVar17,(uint)ppuVar18 & 0xff);
      if ((int)ppuVar24 == 0) {
        _swift_errorRelease(unaff_x24);
        _objc_release_x20();
      }
      else {
        ppuVar20 = (undefined **)0xc;
        _swift_slowAlloc(0xc,0xffffffffffffffff);
        ppuVar21 = (undefined **)0x8;
        _swift_slowAlloc(8,0xffffffffffffffff);
        *(int *)ppuVar20 = (int)_UNK_100d65518;
        _swift_errorRetain(unaff_x24);
        ppuVar24 = unaff_x24;
        __swift_stdlib_bridgeErrorToNSError();
        *(undefined ***)((long)ppuVar20 + 4) = ppuVar24;
        *ppuVar21 = (undefined *)ppuVar24;
        __os_log_impl(0x100000000,ppuVar17,(uint)ppuVar18 & 0xff,"Failed to list signing-assets: %@"
                      ,ppuVar20,0xc);
        candidate_100009c1c(ppuVar21,0x1010d6530);
        _swift_slowDealloc(ppuVar21,0xffffffffffffffff,0xffffffffffffffff);
        _swift_slowDealloc(ppuVar20,0xffffffffffffffff,0xffffffffffffffff);
        _objc_release_x20();
        _swift_errorRelease(unaff_x24);
      }
      goto LAB_1001048f8;
    }
    (**(code **)(puVar19 + 8))(ppuVar24,ppuVar22);
    ppuVar17 = ppuVar24;
LAB_100104178:
    ppuVar18 = &PTR_DAT_1010d1000;
    puVar23 = puVar23 + 1;
  } while (puStack_c8 != puVar23);
  _swift_bridgeObjectRelease(ppuVar21);
  ppuVar4 = ppuStack_108;
LAB_1001048f8:
  ppuVar6 = ppuVar4;
  (**(code **)(puVar19 + 8))(ppuVar4,ppuVar22);
  ppuVar15 = ppuVar4;
LAB_100104908:
  if (*(long *)PTR____stack_chk_guard_100fc2d10 == lStack_70) {
    return ppuVar6;
  }
LAB_1001049ec:
  ___stack_chk_fail();
  ppuVar16[-8] = (undefined *)unaff_x24;
  ppuVar16[-7] = (undefined *)ppuVar21;
  ppuVar16[-6] = (undefined *)ppuVar20;
  ppuVar16[-5] = (undefined *)ppuVar18;
  ppuVar16[-4] = (undefined *)ppuVar17;
  ppuVar16[-3] = (undefined *)ppuVar15;
  ppuVar16[-2] = &stack0xfffffffffffffff0;
  ppuVar16[-1] = candidate_1001049f0;
  puVar13 = (undefined8 *)0x1010d5cf0;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(puVar13[-1] + 0x40));
  lVar14 = (long)ppuVar16 + (-0x40 - (extraout_x8_01 + 0xfU & 0xfffffffffffffff0));
  func_0x000100afcc40();
  _objc_msgSend(*puVar13,PTR_s_setDiskCapacity__1010d20a8,0);
  func_0x000100b0c418(0);
  func_0x000100b045c0(0,0,&DAT_1000ff620,0);
  func_0x000100b040bc();
  candidate_100103a5c();
  candidate_10007cdd0();
  candidate_100103d20();
  puVar23 = PTR__OBJC_CLASS___UINotificationFeedbackGenerator_1010d2e30;
  _objc_allocWithZone();
  _objc_msgSend();
  _objc_msgSend();
  lVar3 = 0;
  FUN_100d0cdf0();
  (**(code **)(*(long *)(lVar3 + -8) + 0x38))(lVar14,1,1,lVar3);
  puVar19 = &UNK_100fce7b8;
  _swift_allocObject(&UNK_100fce7b8,0x58,7);
  *(undefined8 *)(puVar19 + 0x10) = 0;
  *(undefined8 *)(puVar19 + 0x18) = 0;
  *(undefined8 *)(puVar19 + 0x20) = 0xd000000000000023;
  *(undefined8 *)(puVar19 + 0x28) = 0x8000000100d15590;
  *(undefined8 *)(puVar19 + 0x30) = 0xd000000000000023;
  *(undefined8 *)(puVar19 + 0x38) = 0x8000000100d155c0;
  *(undefined **)(puVar19 + 0x40) = &__sSp21NIOConcurrencyHelpersE20assertValidAlignmentyyF;
  *(undefined8 *)(puVar19 + 0x48) = 0;
  *(undefined **)(puVar19 + 0x50) = puVar23;
  _objc_retain_x20();
  uVar12 = 0;
  candidate_1000e182c(0,0,lVar14,&UNK_100d67310,puVar19);
  _objc_release_x20();
  _swift_release(uVar12);
  return (undefined **)0x1;
}


/* Address 0x1001049f0 */

undefined8 candidate_1001049f0(void)

{
  undefined8 *puVar1;
  undefined *puVar2;
  long lVar3;
  undefined *puVar4;
  undefined8 uVar5;
  long extraout_x8;
  
  puVar1 = (undefined8 *)0x1010d5cf0;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(puVar1[-1] + 0x40));
  func_0x000100afcc40();
  _objc_msgSend(*puVar1,PTR_s_setDiskCapacity__1010d20a8,0);
  func_0x000100b0c418(0);
  func_0x000100b045c0(0,0,&DAT_1000ff620,0);
  func_0x000100b040bc();
  candidate_100103a5c();
  candidate_10007cdd0();
  candidate_100103d20();
  puVar2 = PTR__OBJC_CLASS___UINotificationFeedbackGenerator_1010d2e30;
  _objc_allocWithZone();
  _objc_msgSend();
  _objc_msgSend();
  lVar3 = 0;
  FUN_100d0cdf0();
  (**(code **)(*(long *)(lVar3 + -8) + 0x38))
            (&stack0xffffffffffffffc0 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0),1,1,lVar3);
  puVar4 = &UNK_100fce7b8;
  _swift_allocObject(&UNK_100fce7b8,0x58,7);
  *(undefined8 *)(puVar4 + 0x10) = 0;
  *(undefined8 *)(puVar4 + 0x18) = 0;
  *(undefined8 *)(puVar4 + 0x20) = 0xd000000000000023;
  *(undefined8 *)(puVar4 + 0x28) = 0x8000000100d15590;
  *(undefined8 *)(puVar4 + 0x30) = 0xd000000000000023;
  *(undefined8 *)(puVar4 + 0x38) = 0x8000000100d155c0;
  *(undefined **)(puVar4 + 0x40) = &__sSp21NIOConcurrencyHelpersE20assertValidAlignmentyyF;
  *(undefined8 *)(puVar4 + 0x48) = 0;
  *(undefined **)(puVar4 + 0x50) = puVar2;
  _objc_retain_x20();
  uVar5 = 0;
  candidate_1000e182c(0,0,&stack0xffffffffffffffc0 + -(extraout_x8 + 0xfU & 0xfffffffffffffff0),
                      &UNK_100d67310,puVar4);
  _objc_release_x20();
  _swift_release(uVar5);
  return 1;
}


/* Address 0x100105178 */

void candidate_100105178(void)

{
  _objc_opt_self(&_OBJC_CLASS___CertificatePair);
  return;
}

