//!
//! @file  SudokuOCR.h
//! @brief SudokuOCR 抽象クラス定義 ファクトリ定義
//!

#pragma once

#include <opencv2/core.hpp>

namespace videosudoku
{
//! @brief 数字を認識する抽象クラス
class SudokuOCR
{
public:
    //! @brief デストラクタ
    virtual ~SudokuOCR() = default;

    //! @brief  初期化処理
    //! @param  file_name モデルファイル
    //! @retval true      成功
    //! @retval false     失敗
    virtual bool initialize(const char *filename) = 0;

    //! @brief  数字認識処理
    //! @param  mat 認識対象画像
    //! @retval 1-9 認識した数値
    //! @retval 0   空白
    virtual int recognize_number(cv::Mat &mat) = 0;

    //! @brief 終了処理
    virtual void finalize() = 0;
};

//! @brief  数字を認識するインスタンスを生成する
//! @param  class_name 生成するクラス名 ["SVMOCR": SVMを利用したクラス]
//! @return 生成したインスタンス
SudokuOCR *sudokuOCRFactory(const char *class_name);
}