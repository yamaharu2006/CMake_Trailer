#include "gtest/gtest.h"

// Sample - use TEST macro
// TEST_CASE : sample_test.SampleTest_UseTestMacro 
TEST(sample_test, SampleTest_UseTestMacro)
{
    EXPECT_EQ(1, 1);
    EXPECT_NE(0, 1);
    EXPECT_TRUE(true);
    EXPECT_FALSE(false);
}

// Sample - use TEST_F macro
namespace sample_gtest
{
    // テスト対象となるクラス Foo のためのフィクスチャ
    class FooTest : public ::testing::Test
    {
    private:
        char* pVal;

    public:
        char* GetTestingVal(){ return pVal; };

    protected:
        // 以降の関数で中身のないものは自由に削除できます．
        FooTest()
        {
            // テスト毎に実行される set-up をここに書きます．
            pVal = new char[2];
        }

        virtual ~FooTest()
        {
            // テスト毎に実行される，例外を投げない clean-up をここに書きます．
            delete pVal;
        }

        // コンストラクタとデストラクタでは不十分な場合．
        // 以下のメソッドを定義することができます：
        virtual void SetUp()
        {
            // このコードは，コンストラクタの直後（各テストの直前）
            // に呼び出されます．
            pVal[0] = 'A';
            pVal[1] = '\0';
        }

        virtual void TearDown()
        {
            // このコードは，各テストの直後（デストラクタの直前）
            // に呼び出されます．
            pVal[0] = '\0';
        }

        // ここで宣言されるオブジェクトは，テストケース内の全てのテストで利用できます．
    };

    // TEST_CASE : 
    TEST_F(FooTest, SampleTest_UseTestfMacro)
    {
        EXPECT_DOUBLE_EQ(3.141592, 3.141592);
        EXPECT_STREQ("A", GetTestingVal());
    }
}
