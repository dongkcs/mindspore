/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINDSPORE_CCSRC_MINDDATA_DATASET_ENGINE_IR_DATASETOPS_SOURCE_IMAGE_FOLDER_NODE_H_
#define MINDSPORE_CCSRC_MINDDATA_DATASET_ENGINE_IR_DATASETOPS_SOURCE_IMAGE_FOLDER_NODE_H_

#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "mindspore/ccsrc/minddata/dataset/engine/ir/cache/dataset_cache.h"
#include "minddata/dataset/include/datasets.h"

namespace mindspore {
namespace dataset {

namespace api {

/// \class ImageFolderNode
/// \brief A Dataset derived class to represent ImageFolder dataset
class ImageFolderNode : public Dataset {
 public:
  /// \brief Constructor
  ImageFolderNode(std::string dataset_dir, bool decode, std::shared_ptr<SamplerObj> sampler, bool recursive,
                  std::set<std::string> extensions, std::map<std::string, int32_t> class_indexing,
                  std::shared_ptr<DatasetCache> cache);

  /// \brief Destructor
  ~ImageFolderNode() = default;

  /// \brief a base class override function to create the required runtime dataset op objects for this class
  /// \return The list of shared pointers to the newly created DatasetOps
  std::vector<std::shared_ptr<DatasetOp>> Build() override;

  /// \brief Parameters validation
  /// \return Status Status::OK() if all the parameters are valid
  Status ValidateParams() override;

  /// \brief Get the shard id of node
  /// \return Status Status::OK() if get shard id successfully
  Status GetShardId(int32_t *shard_id) override;

 private:
  std::string dataset_dir_;
  bool decode_;
  bool recursive_;
  std::shared_ptr<SamplerObj> sampler_;
  std::map<std::string, int32_t> class_indexing_;
  std::set<std::string> exts_;
};
}  // namespace api
}  // namespace dataset
}  // namespace mindspore
#endif  // MINDSPORE_CCSRC_MINDDATA_DATASET_ENGINE_IR_DATASETOPS_SOURCE_IMAGE_FOLDER_NODE_H_
