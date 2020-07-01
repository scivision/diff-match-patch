/*
 * Diff Match and Patch -- Test Harness
 * Copyright 2018 The diff-match-patch Authors.
 * https://github.com/google/diff-match-patch
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <deque>
#include <map>

class diff_match_patch_test {
 public:
  diff_match_patch_test();
  void run_all_tests();

  //  DIFF TEST FUNCTIONS
  void testDiffCommonPrefix();
  void testDiffCommonSuffix();
  void testDiffCommonOverlap();
  void testDiffHalfmatch();
  void testDiffLinesToChars();
  void testDiffCharsToLines();
  void testDiffCleanupMerge();
  void testDiffCleanupSemanticLossless();
  void testDiffCleanupSemantic();
  void testDiffCleanupEfficiency();
  void testDiffPrettyHtml();
  void testDiffText();
  void testDiffDelta();
  void testDiffXIndex();
  void testDiffLevenshtein();
  void testDiffBisect();
  void testDiffMain();

  //  MATCH TEST FUNCTIONS
  void testMatchAlphabet();
  void testMatchBitap();
  void testMatchMain();

  //  PATCH TEST FUNCTIONS
  void testPatchObj();
  void testPatchFromText();
  void testPatchToText();
  void testPatchAddContext();
  void testPatchMake();
  void testPatchSplitMax();
  void testPatchAddPadding();
  void testPatchApply();

 private:
  diff_match_patch dmp;

  // Define equality.
  void assertEquals(const std::wstring &strCase, int n1, int n2);
  void assertEquals(const std::wstring &strCase, const std::wstring &s1, const std::wstring &s2);
  void assertEquals(const std::wstring &strCase, const Diff &d1, const Diff &d2);
  void assertEquals(const std::wstring &strCase, const std::deque<Diff> &list1, const std::deque<Diff> &list2);
//   void assertEquals(const std::wstring &strCase, const std::deque<QVariant> &list1, const std::deque<QVariant> &list2);
//   void assertEquals(const std::wstring &strCase, const QVariant &var1, const QVariant &var2);
  void assertEquals(const std::wstring &strCase, const std::map<wchar_t, int> &m1, const std::map<wchar_t, int> &m2);
  void assertEquals(const std::wstring &strCase, const std::deque<std::wstring> &list1, const std::deque<std::wstring> &list2);
  void assertTrue(const std::wstring &strCase, bool value);
  void assertFalse(const std::wstring &strCase, bool value);
  void assertEmpty(const std::wstring &strCase, const std::deque<std::wstring> &list);

  template<std::size_t I = 0, typename... Args>
  typename std::enable_if<I == sizeof...(Args)>::type
  assertEquals(const std::wstring &strCase, const std::tuple<Args...> &tuple1, const std::tuple<Args...> &tuple2)
  {}
  template<std::size_t I = 0, typename... Args>
  typename std::enable_if<I < sizeof...(Args)>::type
  assertEquals(const std::wstring &strCase, const std::tuple<Args...> &tuple1, const std::tuple<Args...> &tuple2)
  {
    assertEquals(strCase, std::get<I>(tuple1), std::get<I>(tuple2));
    assertEquals<I + 1, Args...>(strCase, tuple1, tuple2);
  }

  // Construct the two texts which made up the diff originally.
  std::deque<std::wstring> diff_rebuildtexts(std::deque<Diff> diffs);
  // Private function for quickly building lists of diffs.
  std::deque<Diff> diffList(
      // Diff(INSERT, L"") is invalid and thus is used as the default argument.
      Diff d1 = Diff(Diff::Operation::Insert, L""), Diff d2 = Diff(Diff::Operation::Insert, L""),
      Diff d3 = Diff(Diff::Operation::Insert, L""), Diff d4 = Diff(Diff::Operation::Insert, L""),
      Diff d5 = Diff(Diff::Operation::Insert, L""), Diff d6 = Diff(Diff::Operation::Insert, L""),
      Diff d7 = Diff(Diff::Operation::Insert, L""), Diff d8 = Diff(Diff::Operation::Insert, L""),
      Diff d9 = Diff(Diff::Operation::Insert, L""), Diff d10 = Diff(Diff::Operation::Insert, L""));
};
