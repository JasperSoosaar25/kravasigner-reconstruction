/* Static pseudocode. Types/signatures can be wrong. Not original source. */

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


/* Address 0x100009b94 */

void candidate_100009b94(void)

{
  long *unaff_x22;
  long lVar1;
  
  lVar1 = *unaff_x22;
  _swift_task_dealloc(*(undefined8 *)(*unaff_x22 + 0x10));
                    /* WARNING: Could not recover jumptable at 0x000100009bd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar1 + 8))();
  return;
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


/* Address 0x1000152fc */

void candidate_1000152fc(undefined8 param_1)

{
  func_0x000100015b88();
  _swift_allocObject();
  func_0x000100015338(0);
  uRam0000000101185910 = param_1;
  return;
}


/* Address 0x100018d24 */

void candidate_100018d24(void)

{
  code *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = PTR__OBJC_CLASS___NSBundle_1010d2dd8;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_bundleIdentifier_1010d1ce8;
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x20();
  if (puVar2 != (undefined *)0x0) {
    FUN_100d0c658();
    _objc_release_x19();
    puRam00000001010d6548 = puVar2;
    puRam00000001010d6550 = puVar3;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x100018dac);
  (*pcVar1)();
}


/* Address 0x100018dcc */

void candidate_100018dcc(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  FUN_100d0a324(0);
  func_0x00010000fb7c();
  candidate_10000fb20(uVar3,0x101185930);
  if (lRam00000001010d4b58 != -1) {
    _swift_once(0x1010d4b58,candidate_100018d24);
  }
  uVar2 = uRam00000001010d6550;
  uVar1 = uRam00000001010d6548;
  _swift_bridgeObjectRetain(uRam00000001010d6550);
  FUN_100d0a318(uVar3,uVar1,uVar2,0x6373694d,0xe400000000000000);
  return;
}


/* Address 0x100020804 */

void candidate_100020804(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(code **)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(param_1 + 0x28);
  _swift_retain(uVar2);
  (*pcVar1)();
                    /* WARNING: Could not recover jumptable at 0x000100d10b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_release_100fc7b78)(uVar2);
  return;
}


/* Address 0x10003cc60 */

void candidate_10003cc60(void)

{
  long lVar1;
  undefined *puVar2;
  long *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  long unaff_x22;
  
  uVar5 = *(undefined8 *)(unaff_x22 + 0x58);
  FUN_100d09dd8(uVar5,*(undefined8 *)(unaff_x22 + 0x10),*(undefined8 *)(unaff_x22 + 0x18));
  lVar1 = 0;
  FUN_100d09de4();
  *(long *)(unaff_x22 + 0x80) = lVar1;
  pcVar4 = *(code **)(*(long *)(lVar1 + -8) + 0x30);
  *(code **)(unaff_x22 + 0x88) = pcVar4;
  (*pcVar4)(uVar5,1,lVar1);
  if ((int)uVar5 != 1) {
    FUN_100d095ec(*(undefined8 *)(unaff_x22 + 0x78),0x404e000000000000,
                  *(undefined8 *)(unaff_x22 + 0x58),0);
    FUN_100d095a4(1);
    puVar2 = PTR__OBJC_CLASS___NSURLSession_1010d2e58;
    _objc_opt_self();
    *(undefined **)(unaff_x22 + 0x90) = puVar2;
    _objc_msgSend();
    _objc_retainAutoreleasedReturnValue();
    *(undefined **)(unaff_x22 + 0x98) = puVar2;
    plVar3 = (long *)(ulong)*(uint *)(
                                     PTR___sSo12NSURLSessionC10FoundationE4data3for8delegateAC4DataV_So13NSURLResponseCtAC10URLRequestV_So0A12TaskDelegate_pSgtYaKFTu_100fc2900
                                     + 4);
    _swift_task_alloc();
    *(long **)(unaff_x22 + 0xa0) = plVar3;
    *plVar3 = unaff_x22;
    plVar3[1] = (long)candidate_10003cd48;
                    /* WARNING: Could not recover jumptable at 0x000100d0d428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)
      PTR___sSo12NSURLSessionC10FoundationE4data3for8delegateAC4DataV_So13NSURLResponseCtAC10URLRequestV_So0A12TaskDelegate_pSgtYaKF_100fc28f8
    )(*(undefined8 *)(unaff_x22 + 0x78),0);
    return;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x10003cd48);
  (*pcVar4)();
}


/* Address 0x10003cd48 */

void candidate_10003cd48(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  long unaff_x20;
  long *unaff_x22;
  
  lVar2 = *unaff_x22;
  *(undefined8 *)(lVar2 + 0xa8) = param_1;
  *(undefined8 *)(lVar2 + 0xb0) = param_2;
  *(long *)(lVar2 + 0xb8) = unaff_x20;
  _swift_task_dealloc(*(undefined8 *)(lVar2 + 0xa0));
  _objc_release_x21();
  if (unaff_x20 == 0) {
    _objc_release_x19();
    pcVar1 = candidate_10003cdc4;
  }
  else {
    pcVar1 = candidate_10003d2fc;
  }
                    /* WARNING: Could not recover jumptable at 0x000100d10c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_task_switch_100fc8578)(pcVar1,0,0);
  return;
}


/* Address 0x10003cdc4 */

void candidate_10003cdc4(void)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long unaff_x22;
  
  uVar4 = *(undefined8 *)(unaff_x22 + 0x80);
  pcVar1 = *(code **)(unaff_x22 + 0x88);
  uVar3 = *(undefined8 *)(unaff_x22 + 0x50);
  FUN_100d09dd8(uVar3,*(undefined8 *)(unaff_x22 + 0x20),*(undefined8 *)(unaff_x22 + 0x28));
  (*pcVar1)(uVar3,1,uVar4);
  if ((int)uVar3 != 1) {
    uVar4 = *(undefined8 *)(unaff_x22 + 0x90);
    FUN_100d095ec(*(undefined8 *)(unaff_x22 + 0x70),0x404e000000000000,
                  *(undefined8 *)(unaff_x22 + 0x50),0);
    FUN_100d095a4(1);
    _objc_msgSend(uVar4,PTR_s_sharedSession_1010d2750);
    _objc_retainAutoreleasedReturnValue();
    *(undefined8 *)(unaff_x22 + 0xc0) = uVar4;
    plVar2 = (long *)(ulong)*(uint *)(
                                     PTR___sSo12NSURLSessionC10FoundationE4data3for8delegateAC4DataV_So13NSURLResponseCtAC10URLRequestV_So0A12TaskDelegate_pSgtYaKFTu_100fc2900
                                     + 4);
    _swift_task_alloc();
    *(long **)(unaff_x22 + 200) = plVar2;
    *plVar2 = unaff_x22;
    plVar2[1] = (long)candidate_10003ce98;
                    /* WARNING: Could not recover jumptable at 0x000100d0d428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)
      PTR___sSo12NSURLSessionC10FoundationE4data3for8delegateAC4DataV_So13NSURLResponseCtAC10URLRequestV_So0A12TaskDelegate_pSgtYaKF_100fc28f8
    )(*(undefined8 *)(unaff_x22 + 0x70),0);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x10003ce98);
  (*pcVar1)();
}


/* Address 0x10003ce98 */

void candidate_10003ce98(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  long unaff_x20;
  long *unaff_x22;
  
  lVar2 = *unaff_x22;
  *(undefined8 *)(lVar2 + 0xd0) = param_1;
  *(undefined8 *)(lVar2 + 0xd8) = param_2;
  *(long *)(lVar2 + 0xe0) = unaff_x20;
  _swift_task_dealloc(*(undefined8 *)(lVar2 + 200));
  _objc_release_x21();
  if (unaff_x20 == 0) {
    _objc_release_x19();
    pcVar1 = candidate_10003cf14;
  }
  else {
    pcVar1 = candidate_10003d384;
  }
                    /* WARNING: Could not recover jumptable at 0x000100d10c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_task_switch_100fc8578)(pcVar1,0,0);
  return;
}


/* Address 0x10003cf14 */

/* WARNING: Removing unreachable block (ram,0x00010003d0bc) */

void candidate_10003cf14(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  code *pcVar8;
  code *pcVar9;
  undefined8 uVar10;
  long lVar11;
  long unaff_x22;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  uVar5 = *(undefined8 *)(unaff_x22 + 0xa8);
  lVar6 = *(long *)(unaff_x22 + 0xb0);
  uVar10 = *(undefined8 *)(unaff_x22 + 0x48);
  FUN_100d0c6a0(uVar10);
  FUN_100d0c664(uVar5,lVar6,uVar10);
  if (lVar6 != 0) {
    uVar10 = *(undefined8 *)(unaff_x22 + 0xd0);
    lVar7 = *(long *)(unaff_x22 + 0xd8);
    uVar13 = *(undefined8 *)(unaff_x22 + 0x48);
    FUN_100d0c6a0(uVar13);
    FUN_100d0c664(uVar10,lVar7,uVar13);
    if (lVar7 != 0) {
      lVar11 = *(long *)(unaff_x22 + 0xe0);
      candidate_100009960(0,0x1010d6f70,&PTR__OBJC_CLASS___NSFileManager_1010d2e48);
      func_0x000100119428(uVar5,lVar6,0x632e726576726573,0xea00000000007472);
      if (lVar11 == 0) {
        _swift_bridgeObjectRelease(lVar6);
        func_0x000100119428(uVar10,lVar7,0x702e726576726573,0xea00000000006d65);
        _swift_bridgeObjectRelease(lVar7);
        uVar10 = 0;
        FUN_100d0cdb4();
        puVar4 = PTR___sScMMa_100fc8208;
        uVar5 = uVar10;
        FUN_100d0cda8();
        *(undefined8 *)(unaff_x22 + 0xe8) = uVar5;
        uVar5 = 0x1010d6908;
        func_0x000100009e20(0x1010d6908,puVar4,PTR___sScMScAsMc_100fc8210);
        FUN_100d0ccf4(uVar10,uVar5);
                    /* WARNING: Could not recover jumptable at 0x000100d10c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR__swift_task_switch_100fc8578)(candidate_10003d1e0,uVar10,uVar5);
        return;
      }
      uVar5 = *(undefined8 *)(unaff_x22 + 0xd0);
      uVar13 = *(undefined8 *)(unaff_x22 + 0xd8);
      uVar10 = *(undefined8 *)(unaff_x22 + 0xa8);
      uVar12 = *(undefined8 *)(unaff_x22 + 0xb0);
      lVar1 = *(long *)(unaff_x22 + 0x68);
      uVar2 = *(undefined8 *)(unaff_x22 + 0x70);
      uVar14 = *(undefined8 *)(unaff_x22 + 0x60);
      _swift_bridgeObjectRelease(lVar6);
      _swift_bridgeObjectRelease(lVar7);
      func_0x000100009cc0(uVar5,uVar13);
      func_0x000100009cc0(uVar10,uVar12);
      pcVar8 = *(code **)(lVar1 + 8);
      (*pcVar8)(uVar2,uVar14);
      pcVar9 = *(code **)(unaff_x22 + 0x30);
      (*pcVar8)(*(undefined8 *)(unaff_x22 + 0x78),*(undefined8 *)(unaff_x22 + 0x60));
      (*pcVar9)(0);
      _swift_errorRelease(lVar11);
      goto LAB_10003d10c;
    }
    _swift_bridgeObjectRelease(lVar6);
  }
  uVar5 = *(undefined8 *)(unaff_x22 + 0xd0);
  uVar2 = *(undefined8 *)(unaff_x22 + 0xd8);
  uVar10 = *(undefined8 *)(unaff_x22 + 0xa8);
  uVar14 = *(undefined8 *)(unaff_x22 + 0xb0);
  uVar13 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar3 = *(undefined8 *)(unaff_x22 + 0x78);
  uVar12 = *(undefined8 *)(unaff_x22 + 0x60);
  lVar6 = *(long *)(unaff_x22 + 0x68);
  (**(code **)(unaff_x22 + 0x30))(0);
  func_0x000100009cc0(uVar5,uVar2);
  func_0x000100009cc0(uVar10,uVar14);
  pcVar9 = *(code **)(lVar6 + 8);
  (*pcVar9)(uVar13,uVar12);
  (*pcVar9)(uVar3,uVar12);
LAB_10003d10c:
  uVar5 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar10 = *(undefined8 *)(unaff_x22 + 0x50);
  uVar13 = *(undefined8 *)(unaff_x22 + 0x58);
  uVar12 = *(undefined8 *)(unaff_x22 + 0x48);
  _swift_task_dealloc(*(undefined8 *)(unaff_x22 + 0x78));
  _swift_task_dealloc(uVar5);
  _swift_task_dealloc(uVar13);
  _swift_task_dealloc(uVar10);
  _swift_task_dealloc(uVar12);
                    /* WARNING: Could not recover jumptable at 0x00010003d15c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x22 + 8))();
  return;
}


/* Address 0x10003d1e0 */

void candidate_10003d1e0(void)

{
  undefined8 uVar1;
  long unaff_x22;
  
  uVar1 = *(undefined8 *)(unaff_x22 + 0x40);
  _swift_release(*(undefined8 *)(unaff_x22 + 0xe8));
  _objc_msgSend(uVar1,PTR_s_notificationOccurred__1010d1b28,0);
                    /* WARNING: Could not recover jumptable at 0x000100d10c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__swift_task_switch_100fc8578)(candidate_10003d234,0,0);
  return;
}


/* Address 0x10003d234 */

void candidate_10003d234(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  code *pcVar8;
  long unaff_x22;
  undefined8 uVar9;
  
  uVar1 = *(undefined8 *)(unaff_x22 + 0xd0);
  uVar4 = *(undefined8 *)(unaff_x22 + 0xd8);
  uVar2 = *(undefined8 *)(unaff_x22 + 0xa8);
  uVar5 = *(undefined8 *)(unaff_x22 + 0xb0);
  uVar3 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar6 = *(undefined8 *)(unaff_x22 + 0x78);
  uVar9 = *(undefined8 *)(unaff_x22 + 0x60);
  lVar7 = *(long *)(unaff_x22 + 0x68);
  (**(code **)(unaff_x22 + 0x30))(1);
  func_0x000100009cc0(uVar1,uVar4);
  func_0x000100009cc0(uVar2,uVar5);
  pcVar8 = *(code **)(lVar7 + 8);
  (*pcVar8)(uVar3,uVar9);
  (*pcVar8)(uVar6,uVar9);
  uVar1 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar2 = *(undefined8 *)(unaff_x22 + 0x50);
  uVar3 = *(undefined8 *)(unaff_x22 + 0x58);
  uVar9 = *(undefined8 *)(unaff_x22 + 0x48);
  _swift_task_dealloc(*(undefined8 *)(unaff_x22 + 0x78));
  _swift_task_dealloc(uVar1);
  _swift_task_dealloc(uVar3);
  _swift_task_dealloc(uVar2);
  _swift_task_dealloc(uVar9);
                    /* WARNING: Could not recover jumptable at 0x00010003d2f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x22 + 8))();
  return;
}


/* Address 0x10003d2fc */

void candidate_10003d2fc(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long unaff_x22;
  undefined8 uVar5;
  
  uVar4 = *(undefined8 *)(unaff_x22 + 0xb8);
  pcVar1 = *(code **)(unaff_x22 + 0x30);
  (**(code **)(*(long *)(unaff_x22 + 0x68) + 8))
            (*(undefined8 *)(unaff_x22 + 0x78),*(undefined8 *)(unaff_x22 + 0x60));
  (*pcVar1)(0);
  _swift_errorRelease(uVar4);
  uVar4 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar2 = *(undefined8 *)(unaff_x22 + 0x50);
  uVar3 = *(undefined8 *)(unaff_x22 + 0x58);
  uVar5 = *(undefined8 *)(unaff_x22 + 0x48);
  _swift_task_dealloc(*(undefined8 *)(unaff_x22 + 0x78));
  _swift_task_dealloc(uVar4);
  _swift_task_dealloc(uVar3);
  _swift_task_dealloc(uVar2);
  _swift_task_dealloc(uVar5);
                    /* WARNING: Could not recover jumptable at 0x00010003d380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x22 + 8))();
  return;
}


/* Address 0x10003d384 */

void candidate_10003d384(void)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  long unaff_x22;
  undefined8 uVar7;
  
  lVar1 = *(long *)(unaff_x22 + 0x68);
  uVar5 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar4 = *(undefined8 *)(unaff_x22 + 0x60);
  func_0x000100009cc0(*(undefined8 *)(unaff_x22 + 0xa8),*(undefined8 *)(unaff_x22 + 0xb0));
  pcVar6 = *(code **)(lVar1 + 8);
  (*pcVar6)(uVar5,uVar4);
  uVar5 = *(undefined8 *)(unaff_x22 + 0xe0);
  pcVar2 = *(code **)(unaff_x22 + 0x30);
  (*pcVar6)(*(undefined8 *)(unaff_x22 + 0x78),*(undefined8 *)(unaff_x22 + 0x60));
  (*pcVar2)(0);
  _swift_errorRelease(uVar5);
  uVar5 = *(undefined8 *)(unaff_x22 + 0x70);
  uVar4 = *(undefined8 *)(unaff_x22 + 0x50);
  uVar3 = *(undefined8 *)(unaff_x22 + 0x58);
  uVar7 = *(undefined8 *)(unaff_x22 + 0x48);
  _swift_task_dealloc(*(undefined8 *)(unaff_x22 + 0x78));
  _swift_task_dealloc(uVar5);
  _swift_task_dealloc(uVar3);
  _swift_task_dealloc(uVar4);
  _swift_task_dealloc(uVar7);
                    /* WARNING: Could not recover jumptable at 0x00010003d424. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(unaff_x22 + 8))();
  return;
}


/* Address 0x10003d428 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void candidate_10003d428(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  ulong *puVar6;
  ulong *puVar7;
  undefined **ppuVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulong *puVar12;
  long extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  long extraout_x8_02;
  long lVar13;
  long lVar14;
  ulong *puVar15;
  undefined8 uVar16;
  long lVar17;
  undefined8 *puVar18;
  ulong *puVar19;
  ulong auStack_c0 [5];
  long lStack_98;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  
  lVar1 = 0;
  auStack_c0[2] = param_3;
  auStack_c0[3] = param_4;
  auStack_c0[4] = param_2;
  FUN_100d0bfe0();
  lStack_98 = *(long *)(lVar1 + -8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lStack_98 + 0x40));
  lVar14 = (long)auStack_c0 - (extraout_x8 + 0xfU & 0xfffffffffffffff0);
  uVar2 = 0;
  FUN_100d0c034();
  lVar17 = *(long *)(uVar2 - 8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lVar17 + 0x40));
  lVar13 = lVar14 - (extraout_x8_00 + 0xfU & 0xfffffffffffffff0);
  lVar3 = 0;
  func_0x0001001b23c0();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar3 + -8) + 0x40));
  puVar15 = (ulong *)(lVar13 - (extraout_x8_01 + 0xfU & 0xfffffffffffffff0));
  lVar3 = 0x1010d6f50;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar3 + -8) + 0x40));
  puVar18 = (undefined8 *)((long)puVar15 - (extraout_x8_02 + 0xfU & 0xfffffffffffffff0));
  candidate_1000152b8(param_1,puVar18,0x1010d6f50);
  puVar4 = puVar18;
  _swift_getEnumCaseMultiPayload(puVar18,lVar3);
  lVar3 = lStack_98;
  if ((int)puVar4 == 1) {
    uVar16 = *puVar18;
    candidate_100009960(0,0x1010d5cc8,&PTR__OBJC_CLASS___OS_dispatch_queue_1010d2e28);
    FUN_100d0d4e0();
    puVar5 = &UNK_100fca4c8;
    _swift_allocObject(&UNK_100fca4c8,0x18,7);
    *(undefined8 *)(puVar5 + 0x10) = uVar16;
    pcStack_70 = (code *)&DAT_1000400dc;
    puStack_90 = PTR___NSConcreteStackBlock_100fc2c68;
    uStack_88 = _UNK_100d64030;
    pcStack_80 = candidate_100020804;
    puStack_78 = &UNK_100fca4e0;
    ppuVar8 = &puStack_90;
    puStack_68 = puVar5;
    __Block_copy(ppuVar8);
    puVar5 = puStack_68;
    _swift_errorRetain(uVar16);
    _swift_release(puVar5);
    FUN_100d0c004(lVar13);
    puStack_90 = PTR___swiftEmptyArrayStorage_100fc7890;
    uVar9 = 0x1010d5cd0;
    func_0x000100009e20(0x1010d5cd0,PTR___s8Dispatch0A13WorkItemFlagsVMa_100fc7e20,
                        PTR___s8Dispatch0A13WorkItemFlagsVs10SetAlgebraAAMc_100fc7e30);
    uVar10 = 0x1010d5cd8;
    candidate_1000095e8(0x1010d5cd8);
    uVar11 = uVar10;
    func_0x000100009918();
    FUN_100d0db10(lVar14,&puStack_90,uVar10,uVar11,lVar1,uVar9);
    FUN_100d0d4f8(0,lVar13,lVar14,ppuVar8);
    __Block_release(ppuVar8);
    _objc_release_x28();
    _swift_errorRelease(uVar16);
    (**(code **)(lStack_98 + 8))(lVar14,lVar1);
    (**(code **)(lVar17 + 8))(lVar13,uVar2);
  }
  else {
    puVar12 = puVar15;
    auStack_c0[0] = uVar2;
    auStack_c0[1] = lVar17;
    func_0x000100018ca4(puVar18,puVar15);
    puVar6 = (ulong *)puVar15[1];
    if (puVar6 == (ulong *)0x0) {
      FUN_100d09cd0();
      puVar7 = (ulong *)0x0;
      puVar19 = puVar6;
    }
    else {
      puVar7 = puVar6;
      puVar19 = (ulong *)*puVar15;
      puVar12 = puVar6;
    }
    lVar17 = lRam00000001010d4b50;
    _swift_bridgeObjectRetain(puVar7);
    if (lVar17 != -1) {
      _swift_once(0x1010d4b50,candidate_1000152fc);
    }
    uVar9 = uRam0000000101185910;
    puVar6 = puVar19;
    func_0x000100017c78(puVar19,puVar12);
    uVar2 = auStack_c0[3];
    if (((ulong)puVar6 & 1) == 0) {
      _swift_retain(auStack_c0[3]);
      func_0x000100017f20(auStack_c0[4],puVar15,puVar19,puVar12,0,uVar9,auStack_c0[2],uVar2);
      _swift_bridgeObjectRelease(puVar12);
      _swift_release(uVar2);
    }
    else {
      _swift_bridgeObjectRelease(puVar12);
      candidate_100009960(0,0x1010d5cc8,&PTR__OBJC_CLASS___OS_dispatch_queue_1010d2e28);
      FUN_100d0d4e0();
      pcStack_70 = candidate_10003d8c4;
      puStack_68 = (undefined *)0x0;
      puStack_90 = PTR___NSConcreteStackBlock_100fc2c68;
      uStack_88 = _UNK_100d64030;
      pcStack_80 = candidate_100020804;
      puStack_78 = &UNK_100fca508;
      ppuVar8 = &puStack_90;
      __Block_copy(ppuVar8);
      FUN_100d0c004(lVar13);
      puStack_90 = PTR___swiftEmptyArrayStorage_100fc7890;
      uVar9 = 0x1010d5cd0;
      func_0x000100009e20(0x1010d5cd0,PTR___s8Dispatch0A13WorkItemFlagsVMa_100fc7e20,
                          PTR___s8Dispatch0A13WorkItemFlagsVs10SetAlgebraAAMc_100fc7e30);
      uVar10 = 0x1010d5cd8;
      candidate_1000095e8(0x1010d5cd8);
      uVar11 = uVar10;
      func_0x000100009918();
      FUN_100d0db10(lVar14,&puStack_90,uVar10,uVar11,lVar1,uVar9);
      FUN_100d0d4f8(0,lVar13,lVar14,ppuVar8);
      __Block_release(ppuVar8);
      _objc_release_x25();
      (**(code **)(lVar3 + 8))(lVar14,lVar1);
      (**(code **)(auStack_c0[1] + 8))(lVar13,auStack_c0[0]);
    }
    func_0x0001000112e0(puVar15,&__s12AltSourceKit12ASRepositoryVMa);
  }
  return;
}


/* Address 0x10003d8c4 */

void candidate_10003d8c4(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar2 = 0x726f727245;
  uVar5 = 0xe500000000000000;
  func_0x00010011a098(0x726f727245,0xe500000000000000);
  uVar6 = 0x8000000100d14ed0;
  uVar3 = 0xd000000000000019;
  func_0x00010011a098(0xd000000000000019,0x8000000100d14ed0);
  candidate_100009960(0,0x1010d6910,&PTR__OBJC_CLASS___UIApplication_1010d2eb8);
  puVar4 = PTR__OBJC_CLASS___UIApplication_1010d2eb8;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x24();
  _objc_msgSend(puVar4,PTR_s_rootViewController_1010d1e88);
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x25();
  func_0x00010011b838();
  _objc_release_x24();
  if (puVar4 != (undefined *)0x0) {
    candidate_100009960(0,0x1010d6f38,&PTR__OBJC_CLASS___UIAlertController_1010d2f08);
    func_0x00010011a944(puVar4,0,uVar2,uVar5,uVar3,uVar6,1,0,0,0);
    _swift_bridgeObjectRelease(uVar5);
    _swift_bridgeObjectRelease(uVar6);
                    /* WARNING: Could not recover jumptable at 0x000100d0ffa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR__objc_release_100fc2af8)(puVar4);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x10003da2c);
  (*pcVar1)();
}


/* Address 0x10003da2c */

void candidate_10003da2c(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStack_70 [8];
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined1 auStack_58 [8];
  
  uVar2 = 0x726f727245;
  uVar5 = 0xe500000000000000;
  func_0x00010011a098(0x726f727245,0xe500000000000000);
  _swift_getErrorValue(param_1,auStack_58,auStack_70);
  uVar3 = uStack_68;
  uVar6 = uStack_60;
  FUN_100d0eab8(uStack_68,uStack_60);
  candidate_100009960(0,0x1010d6910,&PTR__OBJC_CLASS___UIApplication_1010d2eb8);
  puVar4 = PTR__OBJC_CLASS___UIApplication_1010d2eb8;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x24();
  _objc_msgSend(puVar4,PTR_s_rootViewController_1010d1e88);
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x25();
  func_0x00010011b838();
  _objc_release_x26();
  if (puVar4 != (undefined *)0x0) {
    candidate_100009960(0,0x1010d6f38,&PTR__OBJC_CLASS___UIAlertController_1010d2f08);
    func_0x00010011a944(puVar4,0,uVar2,uVar5,uVar3,uVar6,1,0,0,0);
    _swift_bridgeObjectRelease(uVar5);
    _swift_bridgeObjectRelease(uVar6);
    _objc_release_x24();
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x10003db94);
  (*pcVar1)();
}


/* Address 0x10003db94 */

/* WARNING: Removing unreachable block (ram,0x00010003de1c) */

void candidate_10003db94(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined8 uVar10;
  long *plVar11;
  long *plVar12;
  long extraout_x8;
  long extraout_x8_00;
  long extraout_x8_01;
  long lVar13;
  long extraout_x12;
  long extraout_x12_00;
  long extraout_x12_01;
  long extraout_x12_02;
  long lVar14;
  code *pcVar15;
  undefined *puVar16;
  code *pcVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  code *pcVar21;
  undefined8 auStack_110 [4];
  undefined8 uStack_f0;
  code *pcStack_e8;
  long lStack_e0;
  code *pcStack_d8;
  long lStack_d0;
  long lStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  long lStack_b0;
  long lStack_a8;
  long lStack_a0;
  long lStack_98;
  undefined *puStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 *puStack_78;
  long *plStack_70;
  
  lVar1 = 0;
  uStack_c0 = param_2;
  uStack_b8 = param_3;
  FUN_100d09910();
  lStack_b0 = *(long *)(lVar1 + -8);
  lStack_a8 = lVar1;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lStack_b0 + 0x40));
  lVar20 = (long)&uStack_f0 - (extraout_x8 + 0xfU & 0xfffffffffffffff0);
  lVar1 = 0x1010d5d00;
  lStack_a0 = lVar20;
  candidate_1000095e8();
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(*(long *)(lVar1 + -8) + 0x40));
  lVar20 = lVar20 - (extraout_x8_00 + 0xfU & 0xfffffffffffffff0);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar14 = lVar20 - extraout_x12;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar1 = lVar14 - extraout_x12_00;
  lVar2 = 0;
  FUN_100d09de4();
  lVar19 = *(long *)(lVar2 + -8);
  (*(code *)PTR____chkstk_darwin_100fc2cc8)(*(undefined8 *)(lVar19 + 0x40));
  lVar13 = lVar1 - (extraout_x8_01 + 0xfU & 0xfffffffffffffff0);
  lStack_c8 = lVar13;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar13 = lVar13 - extraout_x12_01;
  (*(code *)PTR____chkstk_darwin_100fc2cc8)();
  lVar18 = lVar13 - extraout_x12_02;
  if (lRam00000001010d4b50 != -1) {
    _swift_once(0x1010d4b50,candidate_1000152fc);
  }
  func_0x000100016a8c(lVar14,param_1);
  pcVar17 = *(code **)(lVar19 + 0x30);
  lVar3 = lVar14;
  (*pcVar17)(lVar14,1,lVar2);
  if ((int)lVar3 == 1) {
    candidate_100009c1c(lVar14,0x1010d5d00);
    (**(code **)(lVar19 + 0x38))(lVar1,1,1,lVar2);
  }
  else {
    pcVar21 = *(code **)(lVar19 + 0x20);
    lStack_d0 = lVar20;
    (*pcVar21)(lVar13,lVar14,lVar2);
    _objc_opt_self(PTR__OBJC_CLASS___NSFileManager_1010d2e48);
    _objc_msgSend();
    _objc_retainAutoreleasedReturnValue();
    func_0x000100118c1c(lVar1,lVar13,0x323170,0xe300000000000000);
    _objc_release_x20();
    pcVar15 = *(code **)(lVar19 + 8);
    (*pcVar15)(lVar13,lVar2);
    lVar20 = lVar1;
    (*pcVar17)(lVar1,1,lVar2);
    if ((int)lVar20 != 1) {
      (*pcVar21)(lVar18,lVar1,lVar2);
      uVar10 = 0;
      lVar20 = lVar18;
      FUN_100d09dfc();
      uVar4 = 0;
      pcStack_e8 = pcVar21;
      lStack_e0 = lVar20;
      pcStack_d8 = pcVar15;
      FUN_100d09ea4(0,lVar20,uVar10);
      _objc_opt_self(PTR__OBJC_CLASS___NSCharacterSet_1010d2e18);
      _objc_msgSend();
      _objc_retainAutoreleasedReturnValue();
      lVar1 = lStack_a0;
      FUN_100d098bc(lStack_a0);
      _objc_release_x20();
      uVar5 = 0x2b3d26403a3f2f3b;
      FUN_100d098ec(0x2b3d26403a3f2f3b,0xeb00000000202c24);
      puStack_78 = (undefined8 *)uVar4;
      plStack_70 = (long *)lVar20;
      func_0x000100009d3c();
      puVar16 = PTR___sSSN_100fc5a40;
      puVar7 = PTR___sSSN_100fc5a40;
      FUN_100d0d930(lVar1,PTR___sSSN_100fc5a40,uVar5);
      _swift_bridgeObjectRelease(lVar20);
      if (puVar7 == (undefined *)0x0) {
        func_0x000100009cc0(lStack_e0,uVar10);
        (**(code **)(lStack_b0 + 8))(lStack_a0,lStack_a8);
        (*pcStack_d8)(lVar18,lVar2);
        return;
      }
      puStack_78 = (undefined8 *)uStack_c0;
      plStack_70 = (long *)uStack_b8;
      uStack_88 = 0x3436455341422824;
      uStack_80 = 0xee0029545245435f;
      uStack_f0 = uVar10;
      lStack_98 = lVar1;
      puStack_90 = puVar7;
      *(undefined8 *)(lVar18 + -0x10) = uVar5;
      *(undefined8 *)(lVar18 + -8) = uVar5;
      puVar6 = &uStack_88;
      plVar11 = &lStack_98;
      *(undefined **)(lVar18 + -0x20) = puVar16;
      *(undefined8 *)(lVar18 + -0x18) = uVar5;
      FUN_100d0d924(puVar6,plVar11,0,0,0,1,puVar16,puVar16);
      _swift_bridgeObjectRelease(puVar7);
      uStack_88 = 0x4f57535341502824;
      uStack_80 = 0xeb00000000294452;
      puVar16 = PTR_s_password_1010d1db8;
      puStack_78 = puVar6;
      plStack_70 = plVar11;
      _objc_msgSend();
      _objc_retainAutoreleasedReturnValue();
      if (param_1 == 0) {
        param_1 = 0;
        puVar16 = (undefined *)0xe000000000000000;
      }
      else {
        FUN_100d0c658();
        _objc_release_x27();
      }
      lVar1 = lStack_d0;
      lStack_98 = param_1;
      puStack_90 = puVar16;
      *(undefined8 *)(lVar18 + -0x10) = uVar5;
      *(undefined8 *)(lVar18 + -8) = uVar5;
      puVar6 = &uStack_88;
      plVar12 = &lStack_98;
      *(undefined8 *)(lVar18 + -0x18) = uVar5;
      *(undefined **)(lVar18 + -0x20) = PTR___sSSN_100fc5a40;
      FUN_100d0d924(puVar6,plVar12,0,0,0,1,PTR___sSSN_100fc5a40,PTR___sSSN_100fc5a40);
      _swift_bridgeObjectRelease(plVar11);
      _swift_bridgeObjectRelease(puVar16);
      FUN_100d09dd8(lVar1,puVar6,plVar12);
      _swift_bridgeObjectRelease(plVar12);
      lVar13 = lVar1;
      (*pcVar17)(lVar1,1,lVar2);
      lVar20 = lStack_c8;
      if ((int)lVar13 != 1) {
        (*pcStack_e8)(lStack_c8,lVar1,lVar2);
        puVar16 = PTR__OBJC_CLASS___UIApplication_1010d2eb8;
        _objc_opt_self(PTR__OBJC_CLASS___UIApplication_1010d2eb8);
        _objc_msgSend();
        _objc_retainAutoreleasedReturnValue();
        puVar7 = puVar16;
        FUN_100d09d18();
        puVar8 = PTR___swiftEmptyArrayStorage_100fc7890;
        func_0x000100103624(PTR___swiftEmptyArrayStorage_100fc7890);
        uVar5 = 0;
        func_0x000100009dd8(0);
        uVar4 = 0x1010d5de0;
        func_0x000100009e20(0x1010d5de0,&SUB_100009dd8,&UNK_100d64914);
        puVar9 = puVar8;
        FUN_100d0c244(puVar8,uVar5,PTR___sypN_100fc7878 + 8,uVar4);
        _swift_bridgeObjectRelease(puVar8);
        _objc_msgSend(puVar16,PTR_s_openURL_options_completionHandle_1010d1e98,puVar7,puVar9,0);
        _objc_release_x19();
        _objc_release_x20();
        _objc_release_x26();
        func_0x000100009cc0(lStack_e0,uStack_f0);
        pcVar17 = pcStack_d8;
        (*pcStack_d8)(lVar20,lVar2);
        (**(code **)(lStack_b0 + 8))(lStack_a0,lStack_a8);
        (*pcVar17)(lVar18,lVar2);
        return;
      }
      func_0x000100009cc0(lStack_e0,uStack_f0);
      (**(code **)(lStack_b0 + 8))(lStack_a0,lStack_a8);
      (*pcStack_d8)(lVar18,lVar2);
    }
  }
  candidate_100009c1c(lVar1,0x1010d5d00);
  return;
}


/* Address 0x100075244 */

void candidate_100075244(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = 0x8000000100d155f0;
  uVar2 = 0xd000000000000010;
  func_0x00010011a098(0xd000000000000010,0x8000000100d155f0);
  uVar3 = 0xd000000000000022;
  uVar6 = 0x8000000100d15610;
  func_0x00010011a098(0xd000000000000022,0x8000000100d15610);
  candidate_100009960(0,0x1010d6910,&PTR__OBJC_CLASS___UIApplication_1010d2eb8);
  puVar4 = PTR__OBJC_CLASS___UIApplication_1010d2eb8;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x24();
  _objc_msgSend(puVar4,PTR_s_rootViewController_1010d1e88);
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x25();
  func_0x00010011b838();
  _objc_release_x24();
  if (puVar4 != (undefined *)0x0) {
    candidate_100009960(0,0x1010d6f38,&PTR__OBJC_CLASS___UIAlertController_1010d2f08);
    func_0x00010011a944(puVar4,0,uVar2,uVar5,uVar3,uVar6,1,0,0,0);
    _swift_bridgeObjectRelease(uVar5);
    _swift_bridgeObjectRelease(uVar6);
                    /* WARNING: Could not recover jumptable at 0x000100d0ffa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR__objc_release_100fc2af8)(puVar4);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x1000753b8);
  (*pcVar1)();
}


/* Address 0x1000753b8 */

void candidate_1000753b8(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = 0x8000000100d155f0;
  uVar2 = 0xd000000000000010;
  func_0x00010011a098(0xd000000000000010,0x8000000100d155f0);
  uVar3 = 0xd000000000000041;
  uVar6 = 0x8000000100d15640;
  func_0x00010011a098(0xd000000000000041,0x8000000100d15640);
  candidate_100009960(0,0x1010d6910,&PTR__OBJC_CLASS___UIApplication_1010d2eb8);
  puVar4 = PTR__OBJC_CLASS___UIApplication_1010d2eb8;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x24();
  _objc_msgSend(puVar4,PTR_s_rootViewController_1010d1e88);
  _objc_retainAutoreleasedReturnValue();
  _objc_release_x25();
  func_0x00010011b838();
  _objc_release_x24();
  if (puVar4 != (undefined *)0x0) {
    candidate_100009960(0,0x1010d6f38,&PTR__OBJC_CLASS___UIAlertController_1010d2f08);
    func_0x00010011a944(puVar4,0,uVar2,uVar5,uVar3,uVar6,1,0,0,0);
    _swift_bridgeObjectRelease(uVar5);
    _swift_bridgeObjectRelease(uVar6);
                    /* WARNING: Could not recover jumptable at 0x000100d0ffa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR__objc_release_100fc2af8)(puVar4);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x10007552c);
  (*pcVar1)();
}


/* Address 0x1000ff620 */

/* WARNING: Removing unreachable block (ram,0x0001000ff6ec) */

void candidate_1000ff620(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined1 auStack_98 [24];
  undefined *puStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined **ppuStack_60;
  
  puVar1 = PTR__OBJC_CLASS___NSURLSessionConfiguration_1010d2e50;
  _objc_opt_self();
  _objc_msgSend();
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend();
  uVar2 = 0;
  func_0x000100afe150();
  uVar3 = uVar2;
  _swift_allocObject();
  func_0x000100afcbfc(puVar1,candidate_100100294,0,uVar3);
  uVar4 = 0;
  func_0x000100ae1e80();
  puVar5 = (undefined *)0xd000000000000023;
  func_0x000100ad7c2c(0xd000000000000023,0x8000000100d17860,candidate_100100258,0);
  uVar6 = 0;
  func_0x000100ae5bbc();
  uVar3 = uVar6;
  func_0x000100ae55dc();
  _swift_allocObject(uVar6,0x18,7);
  func_0x000100ae55e0(uVar3,0x7fffffffffffffff);
  if (puVar5 == (undefined *)0x0) {
    func_0x000100ae4c2c(0x6400000);
    uVar4 = 0;
    ppuStack_60 = (undefined **)0x0;
    uStack_78 = 0;
    uStack_70 = 0;
  }
  else {
    _swift_beginAccess(puVar5 + 0x10,auStack_98,1,0);
    *(undefined8 *)(puVar5 + 0x10) = 0x1f400000;
    func_0x000100ae4c2c(0x6400000);
    ppuStack_60 = &__s4Nuke9DataCacheCAA0B7CachingAAWP;
  }
  puStack_80 = puVar5;
  uStack_68 = uVar4;
  _swift_retain(puVar5);
  func_0x000100104d9c(&puStack_80,param_1 + 0x28);
  _swift_unknownObjectRelease(*(undefined8 *)(param_1 + 0x50));
  *(undefined8 *)(param_1 + 0x50) = uVar3;
  *(undefined ***)(param_1 + 0x58) = &__s4Nuke10ImageCacheCAA0B7CachingAAWP;
  *(undefined1 *)(param_1 + 0x98) = 1;
  ppuStack_60 = &__s4Nuke10DataLoaderCAA0B7LoadingAAWP;
  uStack_68 = uVar2;
  _swift_release(puVar5);
  puStack_80 = puVar1;
  candidate_10000e92c(param_1);
  func_0x00010003b80c(&puStack_80,param_1);
  *(undefined1 *)(param_1 + 0x82) = 0;
  *(undefined1 *)(param_1 + 0x86) = 0;
  return;
}


/* Address 0x100100258 */

void candidate_100100258(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  func_0x000100ae1e80(0);
  func_0x000100ad7bf8(param_1,param_2,uVar1);
  return;
}


/* Address 0x100100294 */

void candidate_100100294(undefined8 param_1)

{
  func_0x000100afe150(0);
  func_0x000100afcad8(param_1);
  return;
}

