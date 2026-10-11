/* Static pseudocode. Types/signatures can be wrong. Not original source. */

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


/* Address 0x1000152fc */

void candidate_1000152fc(undefined8 param_1)

{
  func_0x000100015b88();
  _swift_allocObject();
  func_0x000100015338(0);
  uRam0000000101185910 = param_1;
  return;
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
    _swift_once(0x1010d4b58,&DAT_100018d24);
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
    plVar3[1] = (long)&DAT_10003cd48;
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
  func_0x000100afcbfc(puVar1,&DAT_100100294,0,uVar3);
  uVar4 = 0;
  func_0x000100ae1e80();
  puVar5 = (undefined *)0xd000000000000023;
  func_0x000100ad7c2c(0xd000000000000023,0x8000000100d17860,&DAT_100100258,0);
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

